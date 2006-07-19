# $NetBSD: fetch.mk,v 1.14 2006/07/19 14:03:59 jlam Exp $

_MASTER_SITE_BACKUP=	${MASTER_SITE_BACKUP:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}
_MASTER_SITE_OVERRIDE=	${MASTER_SITE_OVERRIDE:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?=	${MASTER_SITE_BACKUP:=LOCAL_PORTS/}

ALLFILES?=	${DISTFILES} ${PATCHFILES}
ALLFILES:=	${ALLFILES:O:u}		# remove duplicates
CKSUMFILES?=	${ALLFILES}
.for __tmp__ in ${IGNOREFILES}
CKSUMFILES:=	${CKSUMFILES:N${__tmp__}}
.endfor

# List of all files, with ${DIST_SUBDIR} in front.  Used for fetch and checksum.
.if defined(DIST_SUBDIR)
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
_DISTFILES?=	${DISTFILES:S/^/${DIST_SUBDIR}\//}
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
_PATCHFILES?=	${PATCHFILES:S/^/${DIST_SUBDIR}\//}
.else
_CKSUMFILES?=	${CKSUMFILES}
_DISTFILES?=	${DISTFILES}
_IGNOREFILES?=	${IGNOREFILES}
_PATCHFILES?=	${PATCHFILES}
.endif
_ALLFILES?=	${_DISTFILES} ${_PATCHFILES}

_BUILD_DEFS+=	_DISTFILES _PATCHFILES

# Set up _ORDERED_SITES to work out the exact list of sites for every file,
# using the dynamic sites script, or sorting according to the master site
# list or the patterns in MASTER_SORT or MASTER_SORT_REGEX as appropriate.
# No actual sorting is done until _ORDERED_SITES is expanded.
#
.if defined(MASTER_SORT) || defined(MASTER_SORT_REGEX)
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S/./\\./g:C/.*/:\/\/[^\/]*&\//}

_MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S/\\/\\\\/g}"; }
.  for srt in ${MASTER_SORT_REGEX}
_MASTER_SORT_AWK+= /${srt:C/\//\\\//g}/ { good["${srt:S/\\/\\\\/g}"] = good["${srt:S/\\/\\\\/g}"] " " $$0 ; next; }
.  endfor
_MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }

_SORT_SITES_CMD= ${ECHO} $$unsorted_sites | ${AWK} '${_MASTER_SORT_AWK}'
_ORDERED_SITES= "${_MASTER_SITE_OVERRIDE} `${_SORT_SITES_CMD:S/\\/\\\\/g:C/"/\"/g}`"
.else
_ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} $$unsorted_sites
.endif

#
# Associate each file to fetch with the correct site(s).
#
.if defined(DYNAMIC_MASTER_SITES)
.  for fetchfile in ${_ALLFILES}
SITES_${fetchfile:T:S/=/--/}?= `${SH} ${FILESDIR}/getsite.sh ${fetchfile:T}`
SITES.${fetchfile:T:S/=/--/}?=	${SITES_${fetchfile:T:S/=/--/}}
.  endfor
.endif
.if !empty(_DISTFILES)
.  for fetchfile in ${_DISTFILES}
SITES_${fetchfile:T:S/=/--/}?= ${MASTER_SITES}
SITES.${fetchfile:T:S/=/--/}?=	${SITES_${fetchfile:T:S/=/--/}}
.  endfor
.endif
.if !empty(_PATCHFILES)
.  for fetchfile in ${_PATCHFILES}
SITES_${fetchfile:T:S/=/--/}?= ${PATCH_SITES}
SITES.${fetchfile:T:S/=/--/}?=	${SITES_${fetchfile:T:S/=/--/}}
.  endfor
.endif

######################################################################
### fetch (PUBLIC)
######################################################################
### fetch is a public target to fetch all of the package distribution
### files.
###
_FETCH_TARGETS+=	bootstrap-depends
_FETCH_TARGETS+=	check-vulnerable
_FETCH_TARGETS+=	pre-fetch
_FETCH_TARGETS+=	do-fetch
_FETCH_TARGETS+=	post-fetch

.PHONY: fetch
.if !target(fetch)
fetch: ${_FETCH_TARGETS}
.endif

######################################################################
### pre-fetch, do-fetch, post-fetch (PUBLIC, override)
######################################################################
### {pre,do,post}-fetch are the heart of the package-customizable
### fetch targets, and may be overridden within a package Makefile.
###
.PHONY: pre-fetch do-fetch post-fetch

.if !target(do-fetch)
do-fetch: ${_ALLFILES:S/^/${DISTDIR}\//}
	@${DO_NADA}
.endif

.if !target(pre-fetch)
pre-fetch:
	@${DO_NADA}
.endif

.if !target(post-fetch)
post-fetch:
	@${DO_NADA}
.endif

.for _file_ in ${_ALLFILES}
.  if empty(PKG_RESUME_TRANSFERS:M[yY][eE][sS]) && \
      exists(${DISTDIR}/${_file_})
${DISTDIR}/${_file_}:
	@${DO_NADA}
.  else
${DISTDIR}/${_file_}: fetch-check-interactive do-fetch-file error-check
.  endif
.endfor

######################################################################
### fetch-check-interactive (PRIVATE)
######################################################################
### fetch-check-interactive is a macro target that is inserted at the
### head of a target's command list, and will check whether the fetch
### stage for this package requires user interaction to proceed.
###
.PHONY: fetch-check-interactive
fetch-check-interactive: .USEBEFORE
.if !empty(INTERACTIVE_STAGE:Mfetch) && defined(BATCH)
	@${TEST} ! -f ${.TARGET} || exit 0;				\
	${ERROR_MSG} "The fetch stage of this package requires user interaction to download"; \
	${ERROR_MSG} "the distfiles.  Please fetch the distfiles manually and place them in:"; \
	${ERROR_MSG} "    ${_DISTDIR}";					\
	if ${TEST} -n ${MASTER_SITES:Q}""; then				\
		${ERROR_MSG} "The distfiles are available from:";	\
		for site in ${MASTER_SITES}; do				\
			${ERROR_MSG} "    $$site";			\
		done;							\
	fi;								\
	if ${TEST} -n ${HOMEPAGE:Q}""; then				\
		${ERROR_MSG} "See the following URL for more details:";	\
		${ERROR_MSG} "    "${HOMEPAGE:Q};			\
	fi;								\
	${TOUCH} ${_INTERACTIVE_COOKIE};				\
	exit 1
.elif defined(FETCH_MESSAGE) && !empty(FETCH_MESSAGE)
	@${TEST} ! -f ${.TARGET} || exit 0;				\
	${ERROR_MSG} "======================================================================"; \
	${ERROR_MSG} "";						\
	for line in ${FETCH_MESSAGE}; do ${ERROR_MSG} "$$line"; done;	\
	${ERROR_MSG} "";						\
	${ERROR_MSG} "======================================================================"; \
	exit 1
.else
	@${DO_NADA}
.endif

######################################################################
### do-fetch-file (PRIVATE)
######################################################################
### do-fetch-file is a macro target that runs the "fetch" script to
### transfer the files from the appropriate sites if needed.
###
#
# FETCH_CMD is the program used to fetch files.  It must understand
#	fetching files located via URLs, e.g. NetBSD's ftp, net/tnftp,
#	etc.  The default value is set in pkgsrc/mk/defaults/mk.conf.
#
# The following variables are all lists of options to pass to he command
# used to do the actual fetching of the file.
#
# FETCH_BEFORE_ARGS appear before all other options on the command line.
#
# FETCH_AFTER_ARGS appear after all other options on the command line.
#
# FETCH_RESUME_ARGS appears just after FETCH_BEFORE_ARGS and is the set
#	of options for causing the command to resume a previous transfer.
#
# FETCH_OUTPUT_ARGS is a set of options for specifying the name of the
#	local file that will hold the contents of the fetched file.
#
# FAILOVER_FETCH, if defined, will cause a checksum to be performed during
#	a fetch to verify the transferred file is correct; if the checksum
#	is incorrect, then the next site will be tried.
#
# PKG_RESUME_TRANSFERS is a yes/no variable that causes the fetch script
#	to try to resume interrupted file transfers to avoid downloading
#	the whole file.  The default is set in pkgsrc/mk/defaults/mk.conf.
#
#FETCH_CMD?=		ftp	# default is set by pkgsrc/mk/defaults/mk.conf
FETCH_BEFORE_ARGS?=	${_FETCH_BEFORE_ARGS.${FETCH_CMD:T}}
FETCH_AFTER_ARGS?=	${_FETCH_AFTER_ARGS.${FETCH_CMD:T}}
FETCH_RESUME_ARGS?=	${_FETCH_RESUME_ARGS.${FETCH_CMD:T}}
FETCH_OUTPUT_ARGS?=	${_FETCH_OUTPUT_ARGS.${FETCH_CMD:T}}

_FETCH_BEFORE_ARGS.ftp=		# empty
# If this host is behind a filtering firewall, use passive ftp(1)
_FETCH_BEFORE_ARGS.ftp+=	${PASSIVE_FETCH:D-p}
_FETCH_AFTER_ARGS.ftp=		# empty
_FETCH_RESUME_ARGS.ftp=		-R
_FETCH_OUTPUT_ARGS.ftp=		-o

_FETCH_CMD=	${SETENV} CHECKSUM=${_CHECKSUM_CMD:Q}			\
			CP=${TOOLS_CP:Q}				\
			ECHO=${TOOLS_ECHO:Q}				\
			FETCH_CMD=${FETCH_CMD:Q}			\
			FETCH_BEFORE_ARGS=${FETCH_BEFORE_ARGS:Q}	\
			FETCH_AFTER_ARGS=${FETCH_AFTER_ARGS:Q}		\
			FETCH_RESUME_ARGS=${FETCH_RESUME_ARGS:Q}	\
			FETCH_OUTPUT_ARGS=${FETCH_OUTPUT_ARGS:Q}	\
			MKDIR=${TOOLS_MKDIR:Q} MV=${TOOLS_MV:Q}		\
			TEST=${TOOLS_TEST:Q} TOUCH=${TOOLS_TOUCH:Q}	\
			WC=${TOOLS_WC:Q}				\
		${SH} ${PKGSRCDIR}/mk/fetch/fetch

_FETCH_ARGS+=	${FAILOVER_FETCH:D-c}
.if exists(${DISTINFO_FILE})
_FETCH_ARGS+=	-f ${DISTINFO_FILE:Q}
.endif
.if !empty(PKG_RESUME_TRANSFERS:M[yY][eE][sS])
_FETCH_ARGS+=	-r
.endif
_FETCH_ARGS+=	-d ${DIST_SUBDIR:U.}

.PHONY: do-fetch-file
do-fetch-file: .USE
	@${STEP_MSG} "Fetching ${.TARGET:T}"
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} -n {DIST_PATH:Q}""; then				\
		for d in "" ${DIST_PATH:S/:/ /g}; do			\
			case $$d in					\
			""|${DISTDIR})	continue ;;			\
			esac;						\
			file="$$d/${DIST_SUBDIR}/${TARGET:T}";		\
			if ${TEST} -f $$file; then			\
				${ECHO} "Using $$file";			\
				${RM} -f ${TARGET};			\
				${LN} -s $$file ${.TARGET};		\
			fi;						\
		done;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	unsorted_sites="${SITES.${.TARGET:T:S/=/--/}} ${_MASTER_SITE_BACKUP}"; \
	cd ${.TARGET:H:S/\/${DIST_SUBDIR}$//} &&			\
	${_FETCH_CMD} ${_FETCH_ARGS} ${.TARGET:T} ${_ORDERED_SITES}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} ! -f ${.TARGET}; then				\
		${ERROR_MSG} "Could not fetch the following file:";	\
		${ERROR_MSG} "    ${.TARGET:T}";			\
		${ERROR_MSG} "";					\
		${ERROR_MSG} "Please retrieve this file manually into:"; \
		${ERROR_MSG} "    ${.TARGET:H}";			\
		exit 1;							\
	fi

######################################################################
### mirror-distfiles (PUBLIC)
######################################################################
### mirror-distfiles is a public target that is mostly of use only to
### sites that wish to provide distfiles that others may fetch.  It
### only fetches distfiles that are freely re-distributable by setting
### NO_SKIP (see bsd.fetch-vars.mk).
###
.PHONY: mirror-distfiles
.if defined(NO_SRC_ON_FTP)
mirror-distfiles:
	@${DO_NADA}
.else
mirror-distfiles: fetch
.endif

# XXX
# XXX Is this target actually used? (jlam 20060718)
# XXX
.PHONY: show-distfiles
.if !target(show-distfiles)
show-distfiles:
.  if defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.  else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for file in "" ${_CKSUMFILES}; do				\
		if [ "X$$file" = "X" ]; then continue; fi;		\
		${ECHO} $$file;						\
	done
.  endif
.endif
