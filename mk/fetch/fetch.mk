# $NetBSD: fetch.mk,v 1.57 2012/12/14 16:46:24 ryoon Exp $

_MASTER_SITE_BACKUP=	${MASTER_SITE_BACKUP:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}
_MASTER_SITE_OVERRIDE=	${MASTER_SITE_OVERRIDE:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?=	${MASTER_SITE_BACKUP:=LOCAL_PORTS/}

# Set up _ORDERED_SITES to work out the exact list of sites for every file,
# using the dynamic sites script, or ordering according to the master site
# list, MASTER_SORT_RANDOM randomization feature, or the patterns in
# MASTER_SORT or MASTER_SORT_REGEX as appropriate.
# No actual sorting is done until _ORDERED_SITES is expanded.
#
.if defined(MASTER_SORT_RANDOM) && !empty(MASTER_SORT_RANDOM:M[yY][eE][sS])
_MASTER_RAND_AWK= BEGIN { srand(seed); ORS = " " } {			\
		n = split($$0, site);					\
		for (i = n; i > 0; i--) {				\
			ir = int(rand() * i + 1);			\
			t = site[i]; site[i] = site[ir]; site[ir] = t;	\
			print site[i]; } }
_RAND_SITES_CMD= | ${AWK} -v seed=$$$$ '${_MASTER_RAND_AWK}'
.endif

.if defined(MASTER_SORT) || defined(MASTER_SORT_REGEX)
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S/./\\./g:C/.*/:\/\/[^\/]*&\//}

_MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S/\\/\\\\/g}"; }
.  for srt in ${MASTER_SORT_REGEX}
_MASTER_SORT_AWK+= /${srt:C/\//\\\//g}/ { good["${srt:S/\\/\\\\/g}"] = good["${srt:S/\\/\\\\/g}"] " " $$0 ; next; }
.  endfor
_MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }
_SORT_SITES_CMD= | ${AWK} '${_MASTER_SORT_AWK}'
.endif

.if defined(_RAND_SITES_CMD) || defined(_SORT_SITES_CMD)
_SORT_SITES_FULL_CMD= ${ECHO} $$unsorted_sites ${_RAND_SITES_CMD} ${_SORT_SITES_CMD}
_ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} `${_SORT_SITES_FULL_CMD:S/\\/\\\\/g:C/"/\"/g}`
.else
_ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} $$unsorted_sites
.endif

#
# Associate each file to fetch with the correct site(s).
#
DYNAMIC_SITES_SCRIPT?=	${FILESDIR}/getsite.sh
DYNAMIC_SITES_CMD?=	${PKGSRC_SETENV} PATH=${PATH:Q} ${SH} ${DYNAMIC_SITES_SCRIPT}
.if exists(${DYNAMIC_SITES_SCRIPT})
.  for fetchfile in ${_ALLFILES}
SITES.${fetchfile:T:S/=/--/}?= `${DYNAMIC_SITES_CMD} ${fetchfile:T}`
.  endfor
.endif
.if !empty(_DISTFILES)
.  for fetchfile in ${_DISTFILES}
SITES.${fetchfile:T:S/=/--/}?= ${MASTER_SITES}
.  endfor
.endif
.if !empty(_PATCHFILES)
.  for fetchfile in ${_PATCHFILES}
SITES.${fetchfile:T:S/=/--/}?= ${PATCH_SITES}
.  endfor
.endif

######################################################################
### fetch (PUBLIC)
######################################################################
### fetch is a public target to fetch all of the package distribution
### files.
###
_FETCH_TARGETS+=	${_PKG_INSTALL_DEPENDS:Dpkg_install-depends}
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
.  if !empty(_ALLFILES)
do-fetch: ${_ALLFILES:S/^/${DISTDIR}\//}
	@${DO_NADA}
.  else
do-fetch:
	@${DO_NADA}
.  endif
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
.if !empty(INTERACTIVE_STAGE:Mfetch) && defined(BATCH) && !defined(FETCH_MESSAGE)
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
# FETCH_CMD is the program used to fetch files for FETCH_USING=custom.
#       It must understand fetching files located via URLs,
#	e.g. NetBSD's ftp, net/tnftp, etc.
#
# The following variables are all lists of options to pass to the command
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
# FETCH_TIMEOUT, if defined, will cause the fetch command to quit on stalled
#	connections after the given amount of seconds.
#       The specific behavior depends on the command used.
#
# FETCH_USE_IPV4_ONLY, if defined, will cause the fetch command to force
#	connecting to only IPv4 addresses.
#

# If this host is behind a filtering firewall, use passive ftp(1)
_FETCH_BEFORE_ARGS.ftp=		${PASSIVE_FETCH:D-p} \
				${FETCH_TIMEOUT:D-q ${FETCH_TIMEOUT}} \
				${FETCH_USE_IPV4_ONLY:D-4}
_FETCH_AFTER_ARGS.ftp=		# empty
_FETCH_RESUME_ARGS.ftp=		-R
_FETCH_OUTPUT_ARGS.ftp=		-o
_FETCH_CMD.ftp=			${TOOLS_PATH.ftp}

_FETCH_BEFORE_ARGS.fetch=	${FETCH_TIMEOUT:D-T ${FETCH_TIMEOUT}} \
				${FETCH_USE_IPV4_ONLY:D-4}
_FETCH_AFTER_ARGS.fetch=	# empty
_FETCH_RESUME_ARGS.fetch=	-r
_FETCH_OUTPUT_ARGS.fetch=	-o
_FETCH_CMD.fetch=		${TOOLS_PATH.fetch}

_FETCH_BEFORE_ARGS.wget=	${PASSIVE_FETCH:D--passive-ftp} \
				--no-check-certificate \
				${FETCH_TIMEOUT:D--timeout=${FETCH_TIMEOUT}} \
				${FETCH_USE_IPV4_ONLY:D--inet4-only}
_FETCH_AFTER_ARGS.wget=		# empty
_FETCH_RESUME_ARGS.wget=	-c
_FETCH_OUTPUT_ARGS.wget=	-O
_FETCH_CMD.wget=		${PREFIX}/bin/wget

_FETCH_BEFORE_ARGS.curl=	${PASSIVE_FETCH:D--ftp-pasv} \
				--fail --insecure --location \
				${FETCH_TIMEOUT:D--connect-timeout ${FETCH_TIMEOUT}} \
				${FETCH_TIMEOUT:D--speed-time ${FETCH_TIMEOUT}} \
				${FETCH_USE_IPV4_ONLY:D--ipv4}
_FETCH_AFTER_ARGS.curl=		-O # must be here to honor -o option
_FETCH_RESUME_ARGS.curl=	-C -
_FETCH_OUTPUT_ARGS.curl=	-o
_FETCH_CMD.curl=		${TOOLS_PATH.curl}

_FETCH_CMD.manual=		${TOOLS_PATH.false}

_FETCH_CMD.custom=		${FETCH_CMD}
_FETCH_BEFORE_ARGS.custom=	${FETCH_BEFORE_ARGS}
_FETCH_AFTER_ARGS.custom=	${FETCH_AFTER_ARGS}
_FETCH_RESUME_ARGS.custom=	${FETCH_RESUME_ARGS}
_FETCH_OUTPUT_ARGS.custom=	${FETCH_OUTPUT_ARGS}

_FETCH_CMD=	${PKGSRC_SETENV} CHECKSUM=${_CHECKSUM_CMD:Q}	\
		CP=${TOOLS_CP:Q}				\
		ECHO=${TOOLS_ECHO:Q}				\
		FTPUSERAGENT=					\
		FETCH_CMD=${_FETCH_CMD.${FETCH_USING}:Q}	\
		FETCH_BEFORE_ARGS=${_FETCH_BEFORE_ARGS.${FETCH_USING}:Q} \
		FETCH_AFTER_ARGS=${_FETCH_AFTER_ARGS.${FETCH_USING}:Q}   \
		FETCH_RESUME_ARGS=${_FETCH_RESUME_ARGS.${FETCH_USING}:Q} \
		FETCH_OUTPUT_ARGS=${_FETCH_OUTPUT_ARGS.${FETCH_USING}:Q} \
		MKDIR=${TOOLS_MKDIR:Q} MV=${TOOLS_MV:Q}		\
		TEST=${TOOLS_TEST:Q} TOUCH=${TOOLS_TOUCH:Q}	\
		WC=${TOOLS_WC:Q}				\
		${SH} ${PKGSRCDIR}/mk/fetch/fetch

_FETCH_ARGS+=	${PKG_VERBOSE:D-v}
.if exists(${DISTINFO_FILE})
_FETCH_ARGS+=	${FAILOVER_FETCH:D-c} -f ${DISTINFO_FILE:Q}
.endif
.if !empty(PKG_RESUME_TRANSFERS:M[yY][eE][sS])
_FETCH_ARGS+=	-r
.endif
.if defined(DIST_SUBDIR) && !empty(DIST_SUBDIR)
_FETCH_ARGS+=	-d ${DIST_SUBDIR}
.endif

.PHONY: do-fetch-file
do-fetch-file: .USE
	@${STEP_MSG} "Fetching ${.TARGET:T}"
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN}								\
	for d in "" ${DIST_PATH:S/:/ /g}; do				\
		case $$d in						\
		""|${DISTDIR})	continue ;;				\
		esac;							\
		file="$$d/${DIST_SUBDIR}/${.TARGET:T}";			\
		if ${TEST} -f $$file; then				\
			${ECHO} "Using $$file";				\
			${RM} -f ${.TARGET};				\
			${LN} -s $$file ${.TARGET};			\
		fi;							\
	done
	${RUN}								\
	unsorted_sites="${SITES.${.TARGET:T:S/=/--/}}";			\
	sites="${_ORDERED_SITES} ${_MASTER_SITE_BACKUP}";		\
	cd ${.TARGET:H:S/\/${DIST_SUBDIR}$//} &&			\
	${_FETCH_CMD} ${_FETCH_ARGS} ${.TARGET:T} $$sites
	${RUN}								\
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
.elif defined(EMUL_PLATFORMS) && !empty(EMUL_PLATFORMS)
mirror-distfiles: emul-fetch
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
	${RUN} ${DO_NADA}
.  else
	${RUN}								\
	for file in "" ${_CKSUMFILES}; do				\
		if [ "X$$file" = "X" ]; then continue; fi;		\
		${ECHO} $$file;						\
	done
.  endif
.endif

.PHONY: depends-fetch
depends-fetch:
	${RUN}                                                          \
	${_DEPENDS_WALK_CMD} ${PKGPATH} |                               \
	while read dir; do                                              \
		${ECHO} "===> Checksumming for $${dir}" &&              \
		cd ${.CURDIR}/../../$$dir &&                            \
		${RECURSIVE_MAKE} ${MAKEFLAGS} fetch;   		\
	done
