# $NetBSD: metadata.mk,v 1.34 2022/11/23 11:17:51 jperkin Exp $

######################################################################
### The targets below are all PRIVATE.
######################################################################

######################################################################
###
### Temporary package meta-data directory.  The contents of this directory
### are copied directly into the real package meta-data directory.
###
PKG_DB_TMPDIR=	${WRKDIR}/.pkgdb

unprivileged-install-hook: ${PKG_DB_TMPDIR}
${PKG_DB_TMPDIR}:
	@${MKDIR} ${.TARGET}

######################################################################
###
### +BUILD_INFO - Package build environment and settings information
###
_BUILD_INFO_FILE=	${PKG_DB_TMPDIR}/+BUILD_INFO
_BUILD_DATE_cmd=	${DATE} "+%Y-%m-%d %H:%M:%S %z"
_BUILD_HOST_cmd=	${UNAME} -a
_METADATA_TARGETS+=	${_BUILD_INFO_FILE}

#
# Skip system libraries on Darwin releases where they do not exist.
#
.if defined(DARWIN_NO_SYSTEM_LIBS)
DARWIN_REQUIRES_FILTER=	${EGREP} -v '\t(/System/Library|/usr/lib)'
.else
DARWIN_REQUIRES_FILTER=	${CAT}
.endif

${_BUILD_INFO_FILE}: ${_PLIST_NOKEYWORDS}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	{								\
		(${_BUILD_DEFS:NPATH:@v@				\
			${ECHO} ${v}=${_BUILD_DEFS.${v}:Q:U${${v}:Q}};	\
		@});							\
		if [ -n "${USE_LANGUAGES}" ]; then			\
			${ECHO} "CC_VERSION=${CC_VERSION}";		\
		fi;							\
		case "${USE_TOOLS}" in					\
		*perl:run*)						\
			${ECHO} "PERL=`${PERL5} --version 2>/dev/null |	\
				${GREP} 'This is perl'`" || ${TRUE};	\
		esac;							\
		case "${USE_TOOLS}" in					\
		*gmake*)						\
			${ECHO} "GMAKE=`${GMAKE} --version |		\
				${GREP} Make`" || ${TRUE};		\
		esac;							\
		${ECHO} "PKGTOOLS_VERSION=${PKGTOOLS_VERSION_REQD}";	\
		if [ -n "${HOMEPAGE}" ]; then				\
			${ECHO} "HOMEPAGE=${HOMEPAGE}";			\
		fi;							\
		${ECHO} "CATEGORIES=${CATEGORIES}";			\
		${ECHO} "MAINTAINER=${MAINTAINER}";			\
		if [ -n "${OWNER}" ]; then				\
			${ECHO} "OWNER=${OWNER}";			\
		fi;							\
		if [ -n "${PREV_PKGPATH}" ]; then			\
			${ECHO} "PREV_PKGPATH=${PREV_PKGPATH}";		\
		fi;							\
		if [ -n "${SUPERSEDES}" ]; then				\
			${ECHO} "SUPERSEDES=${SUPERSEDES}";		\
		fi;							\
		${ECHO} "BUILD_DATE=${_BUILD_DATE_cmd:sh}";		\
		${ECHO} "BUILD_HOST=${_BUILD_HOST_cmd:sh}";		\
	} > ${.TARGET}.tmp
.if !empty(CHECK_SHLIBS_SUPPORTED:M[yY][eE][sS])
	${RUN}								\
	case ${LDD:Q}"" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'` ;; \
	*)	ldd=${LDD:Q} ;;						\
	esac;								\
	bins=`${AWK} '/(^|\/)(bin|sbin|libexec)\// { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${_PLIST_NOKEYWORDS}`; \
	requires="";							\
	case ${OBJECT_FMT:Q}"" in					\
	ELF)								\
		libs=`${AWK} '/\/lib.*\.so(\.[0-9]+)*$$/ { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${_PLIST_NOKEYWORDS}`; \
		if ${TEST} -n "$$bins" -o -n "$$libs"; then		\
			requires=`(${PKGSRC_SETENV} ${LDD_ENV:U} $$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} '$$2 == "=>" && $$3 ~ "/" { print $$3 }' | ${SORT} -u`; \
		fi;							\
		linklibs=`${AWK} '/.*\.so(\.[0-9]+)*$$/ { print "${DESTDIR}${PREFIX}/" $$0 }' ${_PLIST_NOKEYWORDS}`; \
		for i in $$linklibs; do					\
			case "$$i" in					\
			${CHECK_SHLIBS_SKIP:U:@p@${DESTDIR}${PREFIX}/${p}) continue ;;@}	\
			*);;						\
			esac;						\
			if ${TEST} -r $$i -a ! -x $$i -a ! -h $$i; then	\
				${TEST} ${PKG_DEVELOPER:Uno:Q}"" = "no" || \
					${ECHO} "$$i: installed without execute permission; fixing (should use [BSD_]INSTALL_LIB)"; \
				${CHMOD} +x $$i;			\
			fi;						\
		done;							\
		;;							\
	Mach-O)								\
		libs=`${AWK} '/\/lib.*\.dylib/ { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${_PLIST_NOKEYWORDS}`; \
		if ${TEST} "$$bins" != "" -o "$$libs" != ""; then	\
			requires=`($$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${DARWIN_REQUIRES_FILTER} | ${AWK} '/compatibility version/ { print $$1 }' | ${SORT} -u`; \
		fi;							\
		;;							\
	PE)								\
		libs=`${AWK} '/\/.+\.dll$$/ { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${_PLIST_NOKEYWORDS}`; \
		if ${TEST} -n "$$bins" -o -n "$$libs"; then		\
			requires=`(${TRUE} || ${PKGSRC_SETENV} ${LDD_ENV:U} $$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} '$$2 == "=>" && $$3 ~ "/" { print $$3 }' | ${SED} -e 's,^${DESTDIR},,' | ${SORT} -u`; \
		fi;							\
		linklibs=`${AWK} '/.+\.dll$$/ { print "${DESTDIR}${PREFIX}/" $$0 }' ${_PLIST_NOKEYWORDS}`; \
		for i in $$linklibs; do					\
			if ${TEST} -r $$i -a ! -x $$i -a ! -h $$i; then	\
				${TEST} ${PKG_DEVELOPER:Uno:Q}"" = "no" || \
					${ECHO} "$$i: installed without execute permission; fixing (should use [BSD_]INSTALL_LIB)"; \
				${CHMOD} +x $$i;			\
			fi;						\
		done;							\
		;;							\
	esac;								\
	requires=`{ for i in $$requires $$requires; do echo $$i; done; \
		${AWK} '{ print "${PREFIX}/" $$0 }' ${_PLIST_NOKEYWORDS}; } | \
		${SORT} | uniq -c | awk '$$1 == 2 {print $$2}'`; \
	for i in $$libs; do						\
		${ECHO} "PROVIDES=$$i";					\
	done | ${SED} -e 's,^PROVIDES=${DESTDIR},PROVIDES=,'		\
		>> ${.TARGET}.tmp;					\
	for req in $$requires; do					\
		${ECHO} "REQUIRES=$$req" >> ${.TARGET}.tmp;		\
	done
.endif
	${RUN}								\
	sort ${.TARGET}.tmp > ${.TARGET};				\
	rm -f ${.TARGET}.tmp

######################################################################
###
### +BUILD_VERSION - Package build files versioning information
###
### We extract the ident strings from all of the important pkgsrc files
### involved in building the package, i.e. Makefile and patches.
###
_BUILD_VERSION_FILE=	${PKG_DB_TMPDIR}/+BUILD_VERSION
_METADATA_TARGETS+=	${_BUILD_VERSION_FILE}
.if !empty(USE_PKG_ADMIN_DIGEST:M[Yy][Ee][Ss])
${_BUILD_VERSION_FILE}:
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	{								\
		${FIND} ${FILESDIR} -type f 2>/dev/null |		\
		while read f; do					\
			[ -f "$$f" ] && ${ECHO} "$$f";			\
		done;							\
		for f in ${.CURDIR}/Makefile ${PKGDIR}/*; do		\
			[ -f "$$f" ] && ${ECHO} "$$f";			\
		done;							\
		if [ -f ${DISTINFO_FILE:Q} ]; then			\
			${AWK} 'NF == 4 && $$3 == "=" {			\
				gsub("[()]", "", $$2); print $$2;	\
			}' ${DISTINFO_FILE} |				\
			while read file; do				\
				[ -f "${PATCHDIR}/$$file" ] &&		\
					${ECHO} "${PATCHDIR}/$$file";	\
			done;						\
		fi;							\
		if [ -d ${PATCHDIR} ]; then				\
			cd ${PATCHDIR}; for f in *; do			\
				case "$$f" in				\
				"*"|*.orig|*.rej|*~) ;;			\
				patch-*) ${ECHO} "${PATCHDIR}/$$f" ;;	\
				esac;					\
			done;						\
		fi;							\
	} | ${AWK} '{ t=$$0; sub("^${PKGSRCDIR}/", "");			\
			printf "%s %s\n", t, $$0 }' |			\
	while read file relfile; do					\
		printf "%s: " "$$relfile";				\
		${PKG_ADMIN} digest "$$file";				\
	done |								\
	${SORT} -u > ${.TARGET}
.else
${_BUILD_VERSION_FILE}:
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	{								\
		for f in ${.CURDIR}/Makefile ${FILESDIR:tA}/*		\
			${PKGDIR:tA}/*; do				\
			[ -f "$$f" ] && ${ECHO} "$$f";			\
		done;							\
		if [ -f ${DISTINFO_FILE:Q} ]; then			\
			${AWK} 'NF == 4 && $$3 == "=" {			\
				gsub("[()]", "", $$2); print $$2;	\
			}' ${DISTINFO_FILE} |				\
			while read file; do				\
				[ -f "${PATCHDIR}/$$file" ] &&		\
					${ECHO} "${PATCHDIR:tA}/$$file"; \
			done;						\
		fi;							\
		if [ -d ${PATCHDIR} ]; then				\
			cd ${PATCHDIR}; for f in *; do			\
				case "$$f" in				\
				"*"|*.orig|*.rej|*~) ;;			\
				patch-*) ${ECHO} "${PATCHDIR:tA}/$$f" ;; \
				esac;					\
			done;						\
		fi;							\
	} | ${AWK} '{ t=$$0; sub("^${PKGSRCDIR}/", "");			\
			printf "%s %s\n", t, $$0 }' |			\
	while read file relfile; do					\
		${GREP}							\
			-e '\$$NetBSD[:][^$$]*[$$]'			\
			-e '\$$NetBSD\$$'				\
			$$file 2>/dev/null |				\
		${SED} -e "s|^|$$file:|;q";				\
	done |								\
	${AWK} '{ sub("^${PKGSRCDIR}/", "");				\
		  sub(":.*[$$]NetBSD", ":	$$NetBSD");		\
		  sub("[$$][^$$]*$$", "$$");				\
		  print; }' |						\
	${SORT} -u > ${.TARGET}
.endif

######################################################################
###
### +COMMENT - Package comment file
###
### This file contains the one-line description of the package.
###
_COMMENT_FILE=		${PKG_DB_TMPDIR}/+COMMENT
_METADATA_TARGETS+=	${_COMMENT_FILE}

${_COMMENT_FILE}:
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${ECHO} ${COMMENT:Q} > ${.TARGET}

######################################################################
###
### +DESC - Package description file
###
### This file contains the paragraph description of the package.
###
_DESCR_FILE=		${PKG_DB_TMPDIR}/+DESC
_METADATA_TARGETS+=	${_DESCR_FILE}

${_DESCR_FILE}: ${DESCR_SRC}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${CAT} ${.ALLSRC} > ${.TARGET}
.if defined(HOMEPAGE)
	${RUN} {							\
		${ECHO};						\
		${ECHO} "Homepage:";					\
		${ECHO} ""${HOMEPAGE:Q};				\
	} >> ${.TARGET}
.endif

######################################################################
###
### +DISPLAY - Package message file
###
### This file contains important messages which apply to this package,
### and are shown during installation.
###
.if exists(${PKGDIR}/MESSAGE)
MESSAGE_SRC_DFLT=	${PKGDIR}/MESSAGE
.else
.  if exists(${PKGDIR}/MESSAGE.common)
MESSAGE_SRC_DFLT=	${PKGDIR}/MESSAGE.common
.  endif
.  if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC_DFLT+=	${PKGDIR}/MESSAGE.${OPSYS}
.  endif
.  if exists(${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC_DFLT+=	${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g}
.  endif
.  if exists(${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC_DFLT+=	${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g}
.  endif
.endif
MESSAGE_SRC?=	${MESSAGE_SRC_DFLT}

.if ${INIT_SYSTEM} == "rc.d" && exists(${PKGDIR}/MESSAGE.rcd)
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.rcd
.elif ${INIT_SYSTEM} == "smf" && exists(${PKGDIR}/MESSAGE.smf)
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.smf
.endif

.if !empty(MESSAGE_SRC)
_MESSAGE_FILE=		${PKG_DB_TMPDIR}/+DISPLAY
_METADATA_TARGETS+=	${_MESSAGE_FILE}

# Set MESSAGE_SUBST to substitute "${variable}" to "value" in MESSAGE
MESSAGE_SUBST+=	PKGNAME=${PKGNAME}					\
		PKGBASE=${PKGBASE}					\
		PREFIX=${PREFIX}					\
		EMULDIR=${EMULDIR}					\
		EMULSUBDIR=${EMULSUBDIR}				\
		LOCALBASE=${LOCALBASE}					\
		X11BASE=${X11BASE}					\
		SYSCONFBASE=${SYSCONFBASE}				\
		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}			\
		ROOT_GROUP=${REAL_ROOT_GROUP}				\
		ROOT_USER=${REAL_ROOT_USER}

_MESSAGE_SUBST_SED=	${MESSAGE_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}

${_MESSAGE_FILE}: ${MESSAGE_SRC}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${SED} ${_MESSAGE_SUBST_SED} ${.ALLSRC} > ${.TARGET}
.endif	# MESSAGE_SRC

######################################################################
###
### +PRESERVE - Package preserve file
###
### The existence of this file prevents pkg_delete from removing this
### package unless one "force-deletes" the package.
###
.if defined(PKG_PRESERVE)
_PRESERVE_FILE=		${PKG_DB_TMPDIR}/+PRESERVE
_METADATA_TARGETS+=	${_PRESERVE_FILE}

${_PRESERVE_FILE}:
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${DATE} > ${.TARGET}
.endif

######################################################################
###
### +SIZE_PKG - Package size file
###
### This is the total size of the files contained in the package.
###
_SIZE_PKG_FILE=		${PKG_DB_TMPDIR}/+SIZE_PKG
_METADATA_TARGETS+=	${_SIZE_PKG_FILE}

${_SIZE_PKG_FILE}: ${PLIST}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${AWK} 'BEGIN { base = "${PREFIX}/" }				\
		/^@cwd/ { base = $$2 "/" }				\
		/^@/ { next }						\
		{ print base $$0 }' ${PLIST} |				\
	${SORT} -u |							\
	${SED} -e "s,^/,${DESTDIR}/," -e "s/'/'\\\\''/g" -e "s/.*/'&'/" | \
	${XARGS} -n 256 ${LS} -ld 2>/dev/null |				\
	${AWK} 'BEGIN { s = 0 } { s += $$5 } END { print s }'		\
		> ${.TARGET}

######################################################################
###
### +SIZE_ALL - Package size-of-dependencies file
###
### This is the total size of the dependencies that this package was
### built against and the package itself.
###
_SIZE_ALL_FILE=		${PKG_DB_TMPDIR}/+SIZE_ALL
_METADATA_TARGETS+=	${_SIZE_ALL_FILE}

${_SIZE_ALL_FILE}: ${_RDEPENDS_FILE} ${_SIZE_PKG_FILE}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	{								\
		${CAT} ${_SIZE_PKG_FILE} &&				\
		${_FULL_DEPENDS_CMD} | ${SORT} -u |			\
		${XARGS} -n 256 ${PKG_INFO} -qs;			\
	} |								\
	${AWK} 'BEGIN { s = 0 } /^[0-9]+$$/ { s += $$1 } END { print s }' \
		> ${.TARGET}

######################################################################
###
### +DEINSTALL/+INSTALL - Package deinstall and install scripts
###
### These are the scripts invoked by pkg_add(1) and pkg_delete(1)
### as part of the package installation or removal process.
###
### Include scripts.mk to pull in the definitions for the following
### variables:
###
###	_DEINSTALL_FILE (undefined if not required)
###	_INSTALL_FILE (undefined if not required)
###
### This will also add these files to _METADATA_TARGETS.
###
.if ${_USE_NEW_PKGINSTALL:Uno} != "no"
.include "${PKGSRCDIR}/mk/pkgformat/pkg/scripts.mk"
.endif

######################################################################
###
### +CONTENTS - Package manifest file
###
### This file contains the list of files and checksums, along with
### any special "@" commands, e.g. @dirrm.
###
_CONTENTS_FILE=		${PKG_DB_TMPDIR}/+CONTENTS
_METADATA_TARGETS+=	${_CONTENTS_FILE}

_DEPENDS_PLIST=		${WRKDIR}/.PLIST_deps

${_DEPENDS_PLIST}: ${PLIST}
	${RUN} { \
	${ECHO} "@name ${PKGNAME}"; \
	${AWK} '$$1 == "full" { printf "@blddep %s\n@pkgdep %s\n", $$3, $$2; }' < ${_RDEPENDS_FILE}; \
	${AWK} '$$1 == "bootstrap" || $$1 == "build" { printf "@blddep %s\n", $$3; }' < ${_RDEPENDS_FILE}; \
	${CAT} ${PLIST}; } > ${.TARGET}

_PKG_CREATE_ARGS+=				-l -U
_PKG_CREATE_ARGS+=				-B ${_BUILD_INFO_FILE}
_PKG_CREATE_ARGS+=				-b ${_BUILD_VERSION_FILE}
_PKG_CREATE_ARGS+=				-c ${_COMMENT_FILE}
_PKG_CREATE_ARGS+=	${_MESSAGE_FILE:D	-D ${_MESSAGE_FILE}}
_PKG_CREATE_ARGS+=				-d ${_DESCR_FILE}
_PKG_CREATE_ARGS+=				-f ${_DEPENDS_PLIST}
_PKG_CREATE_ARGS+=	${PKG_PRESERVE:D	-n ${_PRESERVE_FILE}}
_PKG_CREATE_ARGS+=				-S ${_SIZE_ALL_FILE}
_PKG_CREATE_ARGS+=				-s ${_SIZE_PKG_FILE}
_PKG_CREATE_ARGS+=	${"${CONFLICTS:M*}" != "":?-C ${CONFLICTS:Q}:}
.if ${_USE_NEW_PKGINSTALL:Uno} != "no"
_PKG_CREATE_ARGS+=	${_INSTALL_FILE:D	-i ${_INSTALL_FILE:Q}}
_PKG_CREATE_ARGS+=	${_DEINSTALL_FILE:D	-k ${_DEINSTALL_FILE:Q}}
.else
_PKG_CREATE_ARGS+=	${INSTALL_FILE:D	${_INSTALL_ARG_cmd:sh}}
_PKG_CREATE_ARGS+=	${DEINSTALL_FILE:D	${_DEINSTALL_ARG_cmd:sh}}
.endif

_PKG_ARGS_INSTALL+=	${_PKG_CREATE_ARGS}
_PKG_ARGS_INSTALL+=	-I ${PREFIX} -p ${DESTDIR}${PREFIX}

.if ${_USE_NEW_PKGINSTALL:Uno} == "no"
_DEINSTALL_ARG_cmd=	if ${TEST} -f ${DEINSTALL_FILE}; then		\
				${ECHO} "-k "${DEINSTALL_FILE:Q};	\
			else						\
				${ECHO};				\
			fi
_INSTALL_ARG_cmd=	if ${TEST} -f ${INSTALL_FILE}; then		\
				${ECHO} "-i "${INSTALL_FILE:Q};		\
			else						\
				${ECHO};				\
			fi
.endif

_CONTENTS_TARGETS+=	${_BUILD_INFO_FILE}
_CONTENTS_TARGETS+=	${_BUILD_VERSION_FILE}
_CONTENTS_TARGETS+=	${_COMMENT_FILE}
.if ${_USE_NEW_PKGINSTALL:Uno} != "no"
_CONTENTS_TARGETS+=	${_DEINSTALL_FILE}
.endif
_CONTENTS_TARGETS+=	${_DEPENDS_FILE}
_CONTENTS_TARGETS+=	${_DESCR_FILE}
.if ${_USE_NEW_PKGINSTALL:Uno} != "no"
_CONTENTS_TARGETS+=	${_INSTALL_FILE}
.endif
_CONTENTS_TARGETS+=	${_MESSAGE_FILE}
_CONTENTS_TARGETS+=	${_DEPENDS_PLIST}
_CONTENTS_TARGETS+=	${_PRESERVE_FILE}
_CONTENTS_TARGETS+=	${_SIZE_ALL_FILE}
_CONTENTS_TARGETS+=	${_SIZE_PKG_FILE}

${_CONTENTS_FILE}: ${_CONTENTS_TARGETS}
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	${PKG_CREATE} ${_PKG_ARGS_INSTALL} -O ${PKGFILE:T} > ${.TARGET}

######################################################################
### _pkgformat-generate-metadata (PRIVATE)
######################################################################
### _pkgformat-generate-metadata is a convenience target for generating
### all of the pkgsrc binary package meta-data files.  It populates
### ${PKG_DB_TMPDIR} with the following files:
###
###	+BUILD_INFO
###	+BUILD_VERSION
###	+COMMENT
###	+CONTENTS
###	+DESC
###	+DEINSTALL (if required)
###	+DISPLAY
###	+INSTALL (if required)
###	+PRESERVE
###	+SIZE_ALL
###	+SIZE_PKG
###
### See the targets above for descriptions of each of those files.
###
.PHONY: _pkgformat-generate-metadata
_pkgformat-generate-metadata: ${_METADATA_TARGETS}

######################################################################
### _pkgformat-clean-metadata (PRIVATE)
######################################################################
### _pkgformat-clean-metadata is a convenience target for removing the
### package meta-data files.  This is essentially the reverse action
### of _pkgformat-generate-metadata.
###
.PHONY: _pkgformat-clean-metadata
_pkgformat-clean-metadata:
	${RUN}${RM} -f ${_METADATA_TARGETS}
