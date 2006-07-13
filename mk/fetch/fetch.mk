# $NetBSD: fetch.mk,v 1.7 2006/07/13 15:23:18 jlam Exp $

######################################################################
### fetch (PUBLIC)
######################################################################
### fetch is a public target to fetch all of the package distribution
### files.
###
.PHONY: fetch
.if !target(fetch)
fetch: bootstrap-depends check-vulnerable pre-fetch do-fetch post-fetch
.endif

# If this host is behind a filtering firewall, use passive ftp(1)
FETCH_BEFORE_ARGS+=	${PASSIVE_FETCH:D-p}

_MASTER_SITE_BACKUP=	${MASTER_SITE_BACKUP:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}
_MASTER_SITE_OVERRIDE=	${MASTER_SITE_OVERRIDE:=${DIST_SUBDIR}${DIST_SUBDIR:D/}}

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?=	${MASTER_SITE_BACKUP:=LOCAL_PORTS/}

ALLFILES?=	${DISTFILES} ${PATCHFILES}
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

BUILD_DEFS+=	_DISTFILES _PATCHFILES

###
### _RESUME_TRANSFER:
###
### Macro to resume a previous transfer, needs to have defined
### the following options in mk.conf:
###
### PKG_RESUME_TRANSFERS
### FETCH_RESUME_ARGS (if FETCH_CMD != default)
### FETCH_OUTPUT_ARGS (if FETCH_CMD != default)
###
### For example if you want to use wget (pkgsrc/net/wget):
###
### FETCH_CMD=wget
### FETCH_RESUME_ARGS=-c
### FETCH_OUTPUT_ARGS=-O
###
### How does it work?
###
### FETCH_CMD downloads the file and saves it temporally into $$bfile.temp
### if the checksum match the correct one, $$bfile.temp is renamed to
### the original name.
###

_RESUME_TRANSFER=						\
	ofile="${DISTDIR}/${DIST_SUBDIR}/$$bfile";		\
	tfile="${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp";		\
	tsize=`${AWK} '/^Size/ && $$2 == '"\"($$file)\""' { print $$4 }' ${DISTINFO_FILE}` || ${TRUE}; \
        osize=`${WC} -c < $$ofile`;				\
								\
	case "$$tsize" in					\
	"")	${ECHO_MSG} "No size in distinfo file (${DISTINFO_FILE})";	\
		break;;						\
	esac;							\
								\
	if [ "$$osize" -eq "$$tsize" ]; then			\
		if [ -f "$$tfile" ]; then			\
			${RM} $$tfile;				\
		fi;						\
		need_fetch=no;					\
	elif [ "$$osize" -lt "$$tsize" -a ! -f "$$tfile" ]; then	\
		${CP} $$ofile $$tfile;				\
		dsize=`${WC} -c < $$tfile`;			\
		need_fetch=yes;					\
	elif [ -f "$$tfile" -a "$$dsize" -gt "$$ossize" ]; then	\
		dsize=`${WC} -c < $$tfile`;			\
		need_fetch=yes;					\
	else							\
		if [ -f "$$tfile" ]; then			\
			dsize=`${WC} -c < $$tfile`;		\
		fi;						\
		need_fetch=yes;					\
	fi;							\
	if [ "$$need_fetch" = "no" ]; then			\
		break;						\
	elif [ -f "$$tfile" -a "$$dsize" -eq "$$tsize" ]; then	\
		${MV} $$tfile $$ofile;				\
		break;						\
	elif [ -n "$$ftp_proxy" -o -n "$$http_proxy" ]; then	\
		${ECHO_MSG} "===> Resume is not supported by ftp(1) using http/ftp proxies.";	\
		break;						\
	elif [ "$$need_fetch" = "yes" -a "$$dsize" -lt "$$tsize" ]; then	\
		if [ "${FETCH_CMD:T}" != "ftp" -a -z "${FETCH_RESUME_ARGS}" ]; then \
			${ECHO_MSG} "=> Resume transfers are not supported, FETCH_RESUME_ARGS is empty."; \
			break;					\
		else						\
			for res_site in $$sites; do		\
				if [ -z "${FETCH_OUTPUT_ARGS}" ]; then \
					${ECHO_MSG} "=> FETCH_OUTPUT_ARGS has to be defined."; \
					break;			\
				fi;				\
				${ECHO_MSG} "=> $$bfile not completed, resuming:";  \
				${ECHO_MSG} "=> Downloaded: $$dsize Total: $$tsize."; \
				${ECHO_MSG};			\
				cd ${DISTDIR};			\
				${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${FETCH_RESUME_ARGS} \
					${FETCH_OUTPUT_ARGS} $${bfile}.temp $${res_site}$${bfile}; \
				if [ $$? -eq 0 ]; then		\
					ndsize=`${WC} -c < $$tfile`;    \
					if [ "$$tsize" -eq "$$ndsize" ]; then \
						${MV} $$tfile $$ofile;  \
					fi;			\
					break;			\
				fi;				\
			done;					\
		fi;						\
	elif [ "$$dsize" -gt "$$tsize" ]; then			\
		${ECHO_MSG} "==> Downloaded file larger than the recorded size."; \
		break;						\
	fi

#
# Define the elementary fetch macros.
#
_FETCH_FILE=								\
	if [ ! -f $$file -a ! -f $$bfile -a ! -h $$bfile ]; then	\
		${ECHO_MSG} "=> $$bfile doesn't seem to exist on this system."; \
		if [ ! -w ${_DISTDIR}/. ]; then 			\
			${ECHO_MSG} "=> Can't download to ${_DISTDIR} (permission denied?)."; \
			exit 1; 					\
		fi; 							\
		for site in $$sites; do					\
			${ECHO_MSG} "=> Attempting to fetch $$bfile from $${site}."; \
			if [ -f ${DISTINFO_FILE} ]; then		\
				${AWK} 'NF == 5 && $$1 == "Size" && $$2 == "('$$bfile')" { printf("=> [%s %s]\n", $$4, $$5) }' ${DISTINFO_FILE}; \
			fi;						\
			if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${bfile} ${FETCH_AFTER_ARGS}; then \
				if [ -n ${FAILOVER_FETCH:Dyes}"" -a -f ${DISTINFO_FILE} -a -f ${_DISTDIR}/$$bfile ]; then \
					alg=`${AWK} 'NF == 4 && $$2 == "('$$file')" && $$3 == "=" {print $$1; exit}' ${DISTINFO_FILE}`; \
					if [ -z "$$alg" ]; then		\
						alg=${PATCH_DIGEST_ALGORITHM};\
					fi;				\
					CKSUM=`${TOOLS_DIGEST} $$alg < ${_DISTDIR}/$$bfile`; \
					CKSUM2=`${AWK} '$$1 == "'$$alg'" && $$2 == "('$$file')" {print $$4; exit}' <${DISTINFO_FILE}`; \
					if [ "$$CKSUM" = "$$CKSUM2" -o "$$CKSUM2" = "IGNORE" ]; then \
						break;			\
					else				\
						${ECHO_MSG} "=> Checksum failure - trying next site."; \
					fi;				\
				elif [ ! -f ${_DISTDIR}/$$bfile ]; then \
					${ECHO_MSG} "=> FTP didn't fetch expected file, trying next site." ; \
				else					\
					break;				\
				fi;					\
			fi						\
		done;							\
		if [ ! -f ${_DISTDIR}/$$bfile ]; then			\
			${ECHO_MSG} "=> Couldn't fetch $$bfile - please try to retrieve this";\
			${ECHO_MSG} "=> file manually into ${_DISTDIR} and try again."; \
			exit 1;						\
		fi;							\
	fi

_CHECK_DIST_PATH=							\
	if [ "X${DIST_PATH}" != "X" ]; then				\
		for d in "" ${DIST_PATH:S/:/ /g}; do			\
			case $$d in "" | ${DISTDIR}) continue;; esac;	\
			if [ -f $$d/${DIST_SUBDIR}/$$bfile ]; then	\
				${ECHO} "Using $$d/${DIST_SUBDIR}/$$bfile"; \
				${RM} -f $$bfile;			\
				${LN} -s $$d/${DIST_SUBDIR}/$$bfile $$bfile; \
				break;					\
			fi;						\
		done;							\
	fi

#
# Set up ORDERED_SITES to work out the exact list of sites for every file,
# using the dynamic sites script, or sorting according to the master site
# list or the patterns in MASTER_SORT or MASTER_SORT_REGEX as appropriate.
# No actual sorting is done until ORDERED_SITES is expanded.
#
.if defined(MASTER_SORT) || defined(MASTER_SORT_REGEX)
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S/./\\./g:C/.*/:\/\/[^\/]*&\//}

MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S/\\/\\\\/g}"; }
.  for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+= /${srt:C/\//\\\//g}/ { good["${srt:S/\\/\\\\/g}"] = good["${srt:S/\\/\\\\/g}"] " " $$0 ; next; }
.  endfor
MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }

SORT_SITES_CMD= ${ECHO} $$unsorted_sites | ${AWK} '${MASTER_SORT_AWK}'
ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} `${SORT_SITES_CMD:S/\\/\\\\/g:C/"/\"/g}`
.else
ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} $$unsorted_sites
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

# This code is only called in a batch case, to check for the presence of
# the distfiles
.PHONY: batch-check-distfiles
batch-check-distfiles:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	gotfiles=yes;							\
	for file in "" ${_ALLFILES}; do					\
		case "$$file" in					\
		"")	continue ;;					\
		*)	if [ ! -f ${DISTDIR}/$$file ]; then		\
				gotfiles=no;				\
			fi ;;						\
		esac;							\
	done;								\
	case "$$gotfiles" in						\
	no)	${ECHO} "*** This package requires user intervention to download the distfiles"; \
		${ECHO} "*** Please fetch the distfiles manually and place them in"; \
		${ECHO} "*** ${DISTDIR}";				\
		[ ! -z "${MASTER_SITES}" ] &&				\
			${ECHO} "*** The distfiles are available from ${MASTER_SITES}";	\
		[ ! -z "${HOMEPAGE}" ] && 				\
			${ECHO} "*** See ${HOMEPAGE} for more details";	\
		${ECHO};						\
		${TOUCH} ${_INTERACTIVE_COOKIE};			\
		${FALSE} ;;						\
	esac

.PHONY: do-fetch
.if !target(do-fetch)
do-fetch:
.  if !empty(_ALLFILES)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -d ${_DISTDIR} || ${MKDIR} ${_DISTDIR}
.    if !empty(INTERACTIVE_STAGE:Mfetch) && defined(BATCH)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${MAKE} ${MAKEFLAGS} batch-check-distfiles
.    else
.      for fetchfile in ${_ALLFILES}
.        if defined(FETCH_MESSAGE) && !empty(FETCH_MESSAGE)
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	${TEST} -f ${DISTDIR:Q}/${fetchfile:Q} || {			\
		h="==============="; h="$$h$$h$$h$$h$$h";		\
		${ECHO} "$$h"; ${ECHO} "";				\
		for l in ${FETCH_MESSAGE}; do ${ECHO} "$$l"; done;	\
		${ECHO} ""; ${ECHO} "$$h";				\
		exit 1;							\
	}
.        elif defined(_FETCH_MESSAGE)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	file="${fetchfile}";						\
	if [ ! -f ${DISTDIR}/$$file ]; then				\
		${_FETCH_MESSAGE};					\
	fi
.        else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${_DISTDIR};							\
	file="${fetchfile}";						\
	bfile="${fetchfile:T}";						\
	unsorted_sites="${SITES.${fetchfile:T:S/=/--/}} ${_MASTER_SITE_BACKUP}"; \
	sites="${ORDERED_SITES}";					\
	${_CHECK_DIST_PATH};						\
	 if ${TEST} "${PKG_RESUME_TRANSFERS:M[Yy][Ee][Ss]}" ; then	\
	 	${_FETCH_FILE}; ${_RESUME_TRANSFER};			\
	 else								\
	 	${_FETCH_FILE};						\
	 fi
.        endif # defined(_FETCH_MESSAGE)
.      endfor
.    endif # INTERACTIVE_STAGE == fetch
.  endif # !empty(_ALLFILES)
.endif

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

.if !target(pre-fetch)
pre-fetch:
	@${DO_NADA}
.endif
.if !target(post-fetch)
post-fetch:
	@${DO_NADA}
.endif

# This is for the use of sites which store distfiles which others may
# fetch - only fetch the distfile if it is allowed to be
# re-distributed freely
.PHONY: mirror-distfiles
mirror-distfiles:
.if !defined(NO_SRC_ON_FTP)
	@${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} fetch NO_SKIP=yes
.endif

# Prints out a script to fetch all needed files (no checksumming).
.PHONY: fetch-list
.if !target(fetch-list)

fetch-list:
	@${ECHO} '#!/bin/sh'
	@${ECHO} '#'
	@${ECHO} '# This is an auto-generated script, the result of running'
	@${ECHO} '# `${MAKE} fetch-list'"'"' in directory "'"`${PWD_CMD}`"'"'
	@${ECHO} '# on host "'"`${UNAME} -n`"'" on "'"`date`"'".'
	@${ECHO} '#'
	@${MAKE} ${MAKEFLAGS} fetch-list-recursive
.endif # !target(fetch-list)

.PHONY: fetch-list-recursive
.if !target(fetch-list-recursive)

fetch-list-recursive:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in `${MAKE} ${MAKEFLAGS} show-all-depends-dirs`; do	\
		(cd ../../$$dir &&					\
		${MAKE} ${MAKEFLAGS} fetch-list-one-pkg			\
		| ${AWK} '						\
		/^[^#]/ { FoundSomething = 1 }				\
		/^unsorted/ { gsub(/[[:space:]]+/, " \\\n\t") }		\
		/^echo/ { gsub(/;[[:space:]]+/, "\n") }			\
		{ block[line_c++] = $$0 }				\
		END { if (FoundSomething)				\
			for (line = 0; line < line_c; line++)		\
				print block[line] }			\
		')							\
	done
.endif # !target(fetch-list-recursive)

.PHONY: fetch-list-one-pkg
.if !target(fetch-list-one-pkg)

fetch-list-one-pkg:
.  if !empty(_ALLFILES)
	@${ECHO}
	@${ECHO} '#'
	@location=`${PWD_CMD} | ${AWK} -F / '{ print $$(NF-1) "/" $$NF }'`; \
		${ECHO} '# Need additional files for ${PKGNAME} ('$$location')...'
.    for fetchfile in ${_ALLFILES}
.      if defined(_FETCH_MESSAGE)
	@(if [ ! -f ${_DISTDIR}/${fetchfile:T} ]; then			\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Prompt user to get ${fetchfile} ('$${filesize-???}' bytes) manually:'; \
		${ECHO} '#';						\
		${ECHO} ${_FETCH_MESSAGE:Q};				\
	fi)
.      elif defined(DYNAMIC_MASTER_SITES)
	@(if [ ! -f ${_DISTDIR}/${fetchfile:T} ]; then			\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Fetch ${fetchfile} ('$${filesize-???}' bytes):'; \
		${ECHO} '#';						\
		${ECHO} '${SH} -s ${fetchfile:T} <<"EOF" |(';		\
		${CAT} ${FILESDIR}/getsite.sh;				\
		${ECHO} EOF;						\
		${ECHO} read unsorted_sites;				\
		${ECHO} 'unsorted_sites="$${unsorted_sites} ${_MASTER_SITE_BACKUP}"'; \
		${ECHO} sites='"'${ORDERED_SITES:Q}'"';			\
		${ECHO} "${MKDIR} ${_DISTDIR}";				\
		${ECHO} 'cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] ||'; \
		${ECHO}	'for site in $$sites; do';			\
		${ECHO} '	${FETCH_CMD} ${FETCH_BEFORE_ARGS} "$${site}${fetchfile:T}" ${FETCH_AFTER_ARGS} && break ||'; \
		${ECHO} '	${ECHO} ${fetchfile:T} not fetched';	\
		${ECHO}	done;						\
		${ECHO} ')';						\
	fi)
.      else
	@(if [ ! -f ${_DISTDIR}/${fetchfile:T} ]; then			\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Fetch ${fetchfile} ('$${filesize-???}' bytes):'; \
		${ECHO} '#';						\
		${ECHO} 'unsorted_sites="${SITES.${fetchfile:T:S/=/--/}} ${_MASTER_SITE_BACKUP}"'; \
		${ECHO} sites='"'${ORDERED_SITES:Q}'"';			\
		${ECHO} "${MKDIR} ${_DISTDIR}";				\
		${ECHO} 'cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] ||'; \
		${ECHO}	'for site in $$sites; do';			\
		${ECHO} '	${FETCH_CMD} ${FETCH_BEFORE_ARGS} "$${site}${fetchfile:T}" ${FETCH_AFTER_ARGS} && break ||'; \
		${ECHO} '	${ECHO} ${fetchfile:T} not fetched';	\
		${ECHO}	done;						\
	fi)
.      endif # defined(_FETCH_MESSAGE) || defined(DYNAMIC_MASTER_SITES)
.    endfor
.  endif # !empty(_ALLFILES)
.endif # !target(fetch-list-one-pkg)
