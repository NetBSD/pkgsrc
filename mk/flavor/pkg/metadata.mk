# $NetBSD: metadata.mk,v 1.17.4.1 2007/05/15 22:29:17 salo Exp $

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
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET}

######################################################################
###
### +BUILD_INFO - Package build environment and settings information
###
_BUILD_INFO_FILE=	${PKG_DB_TMPDIR}/+BUILD_INFO
_BUILD_DATE_cmd=	${DATE} "+%Y-%m-%d %H:%M:%S %z"
_BUILD_HOST_cmd=	${UNAME} -a
_METADATA_TARGETS+=	${_BUILD_INFO_FILE}

${_BUILD_INFO_FILE}: plist
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}.tmp
	${RUN} (${_BUILD_DEFS:NPATH:@v@${ECHO} ${v}=${${v}:Q} ;@})	\
		> ${.TARGET}.tmp
.if !empty(USE_LANGUAGES)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "CC_VERSION=${CC_VERSION}" >> ${.TARGET}.tmp
.endif
.if !empty(USE_TOOLS:Mperl\:run)
	${_PKG_SILENT}${_PKG_DEBUG}					\
        ${ECHO} "PERL=`${PERL5} --version 2>/dev/null | ${GREP} 'This is perl'`" >> ${.TARGET}.tmp
.endif
.if !empty(USE_TOOLS:Mgmake)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "GMAKE=`${GMAKE} --version | ${GREP} Make`" >> ${.TARGET}.tmp
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "PKGTOOLS_VERSION=${PKGTOOLS_VERSION}" >> ${.TARGET}.tmp
.if defined(HOMEPAGE)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "HOMEPAGE=${HOMEPAGE}" >> ${.TARGET}.tmp
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "CATEGORIES=${CATEGORIES}" >> ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "MAINTAINER=${MAINTAINER}" >> ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "BUILD_DATE=${_BUILD_DATE_cmd:sh}" >> ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "BUILD_HOST=${_BUILD_HOST_cmd:sh}" >> ${.TARGET}.tmp
.if !empty(CHECK_SHLIBS_SUPPORTED:M[yY][eE][sS])
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case ${LDD:Q}"" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'` ;; \
	*)	ldd=${LDD:Q} ;;						\
	esac;								\
	bins=`${AWK} '/(^|\/)(bin|sbin|libexec)\// { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${PLIST}`; \
	case ${OBJECT_FMT:Q}"" in					\
	ELF)								\
		libs=`${AWK} '/(^|\/)lib\/lib.*\.so\.[0-9]+$$/ { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${PLIST}`; \
		if ${TEST} -n "$$bins" -o -n "$$libs"; then		\
			requires=`($$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} '$$2 == "=>" && $$3 ~ "/" { print $$3 }' | ${SORT} -u`; \
		fi;							\
		linklibs=`${AWK} '/[^@].*\.so\.[0-9\.]+$$/ { print "${DESTDIR}${PREFIX}/" $$0 }' ${PLIST}`; \
		for i in $$linklibs; do					\
			if ${TEST} -r $$i -a ! -x $$i -a ! -h $$i; then	\
				${TEST} ${PKG_DEVELOPER:Uno:Q}"" = "no" || \
					${ECHO} "$$i: installed without execute permission; fixing (should use [BSD_]INSTALL_LIB)"; \
				${CHMOD} +x $$i;			\
			fi;						\
		done;							\
		;;							\
	Mach-O)								\
		libs=`${AWK} '/(^|\/)lib\/lib.*\.dylib/ { print "${DESTDIR}${PREFIX}/" $$0 } END { exit 0 }' ${PLIST}`; \
		if ${TEST} "$$bins" != "" -o "$$libs" != ""; then	\
			requires=`($$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} '/compatibility version/ { print $$1 }' | ${SORT} -u`; \
		fi;							\
		;;							\
	esac;								\
	for i in "" $$libs; do						\
		${TEST} "$$i" != "" || continue;			\
		${ECHO} "PROVIDES=$$i" >> ${.TARGET}.tmp;		\
	done;								\
	for req in "" $$requires; do					\
		${TEST} "$$req" != "" || continue;			\
		${ECHO} "REQUIRES=$$req" >> ${.TARGET}.tmp;		\
	done
.endif
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	rm -f ${.TARGET};						\
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

${_BUILD_VERSION_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>>${.TARGET}.tmp;						\
	for f in ${.CURDIR}/Makefile ${FILESDIR}/* ${PKGDIR}/*; do	\
		${TEST} ! -f "$$f" || ${ECHO} "$$f";			\
	done
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>>${.TARGET}.tmp;						\
	${TEST} -f ${DISTINFO_FILE:Q} || exit 0;			\
	${CAT} ${DISTINFO_FILE} |					\
	${AWK} 'NF == 4 && $$3 == "=" { gsub("[()]", "", $$2); print $$2 }' | \
	while read file; do						\
		${TEST} ! -f "${PATCHDIR}/$$file" ||			\
			${ECHO} "${PATCHDIR}/$$file";			\
	done
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>>${.TARGET}.tmp;						\
	${TEST} -d ${PATCHDIR} || exit 0;				\
	cd ${PATCHDIR}; for f in *; do					\
		case "$$f" in						\
		"*"|*.orig|*.rej|*~)	;;				\
		patch-*)		${ECHO} "${PATCHDIR}/$$f" ;;	\
		esac;							\
	done
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CAT} ${.TARGET}.tmp |						\
	while read file; do						\
		${GREP} '\$$NetBSD' $$file 2>/dev/null |		\
		${SED} -e "s|^|$$file:|";				\
	done |								\
	${AWK} '{ sub("^${PKGSRCDIR}/", "");				\
		  sub(":.*[$$]NetBSD", ":	$$NetBSD");		\
		  sub("[$$][^$$]*$$", "$$");				\
		  print; }' |						\
	${SORT} -u > ${.TARGET} && ${RM} -f ${.TARGET}.tmp

######################################################################
###
### +COMMENT - Package comment file
###
### This file contains the one-line description of the package.
###
_COMMENT_FILE=		${PKG_DB_TMPDIR}/+COMMENT
_METADATA_TARGETS+=	${_COMMENT_FILE}

${_COMMENT_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${COMMENT:Q} > ${.TARGET}

######################################################################
###
### +DESC - Package description file
###
### This file contains the paragraph description of the package.
###
_DESCR_FILE=		${PKG_DB_TMPDIR}/+DESC
_METADATA_TARGETS+=	${_DESCR_FILE}

${_DESCR_FILE}: ${DESCR_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}
.if defined(HOMEPAGE)
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} "Homepage:" >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ""${HOMEPAGE:Q} >> ${.TARGET}
.endif

######################################################################
###
### +DISPLAY - Package message file
###
### This file contains important messages which apply to this package,
### and are shown during installation.
###
.if !defined(MESSAGE_SRC)
.  if exists(${PKGDIR}/MESSAGE)
MESSAGE_SRC=	${PKGDIR}/MESSAGE
.  else
.    if exists(${PKGDIR}/MESSAGE.common)
MESSAGE_SRC=	${PKGDIR}/MESSAGE.common
.    endif
.    if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${OPSYS}
.    endif
.    if exists(${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g}
.    endif
.    if exists(${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g}
.    endif
.  endif
.endif

.if defined(MESSAGE_SRC)
_MESSAGE_FILE=		${PKG_DB_TMPDIR}/+DISPLAY
_METADATA_TARGETS+=	${_MESSAGE_FILE}

# Set MESSAGE_SUBST to substitute "${variable}" to "value" in MESSAGE
MESSAGE_SUBST+=	PKGNAME=${PKGNAME}					\
		PKGBASE=${PKGBASE}					\
		PREFIX=${PREFIX}					\
		LOCALBASE=${LOCALBASE}					\
		X11PREFIX=${X11PREFIX}					\
		X11BASE=${X11BASE}					\
		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}			\
		ROOT_GROUP=${ROOT_GROUP}				\
		ROOT_USER=${ROOT_USER}

_MESSAGE_SUBST_SED=	${MESSAGE_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}

${_MESSAGE_FILE}: ${MESSAGE_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} |			\
		${SED} ${_MESSAGE_SUBST_SED} > ${.TARGET}

# Display MESSAGE file and optionally mail the contents to
# PKGSRC_MESSAGE_RECIPIENTS.
#
.PHONY: install-display-message
_flavor-register: install-display-message
install-display-message: ${_MESSAGE_FILE}
	@${STEP_MSG} "Please note the following:"
	@${ECHO_MSG} ""
	@${CAT} ${_MESSAGE_FILE}
	@${ECHO_MSG} ""
.  if !empty(PKGSRC_MESSAGE_RECIPIENTS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} "The ${PKGNAME} package was installed on `${HOSTNAME_CMD}` at `date`"; \
	${ECHO} "";							\
	${ECHO} "Please note the following:";				\
	${ECHO} "";							\
	${CAT} ${_MESSAGE_FILE};					\
	${ECHO} "") |							\
	${MAIL_CMD} -s"Package ${PKGNAME} installed on `${HOSTNAME_CMD}`" ${PKGSRC_MESSAGE_RECIPIENTS}
.  endif
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
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${DATE} > ${.TARGET}
.endif

######################################################################
###
### +SIZE_ALL - Package size-of-dependencies file
###
### This is the total size of the dependencies that this package was
### built against.
###
_SIZE_ALL_FILE=		${PKG_DB_TMPDIR}/+SIZE_ALL
_METADATA_TARGETS+=	${_SIZE_ALL_FILE}

${_SIZE_ALL_FILE}: ${_COOKIE.depends}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_DEPENDS_PATTERNS_CMD} |					\
	${XARGS} -n 1 ${_PKG_BEST_EXISTS} | ${SORT} -u |		\
	${XARGS} -n 256 ${PKG_INFO} -qs |				\
	${AWK} 'BEGIN { s = 0 } /^[0-9]+$$/ { s += $$1 } END { print s }' \
		> ${.TARGET}

######################################################################
###
### +SIZE_PKG - Package size file
###
### This is the total size of the files contained in the package.
###
_SIZE_PKG_FILE=		${PKG_DB_TMPDIR}/+SIZE_PKG
_METADATA_TARGETS+=	${_SIZE_PKG_FILE}

${_SIZE_PKG_FILE}: plist
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CAT} ${PLIST} |						\
	${AWK} 'BEGIN { base = "${PREFIX}/" }				\
		/^@cwd/ { base = $$2 "/" }				\
		/^@/ { next }						\
		{ print base $$0 }' |					\
	${SORT} -u |							\
	${SED} -e "s,^/,${DESTDIR}/," -e "s/'/'\\\\''/g" -e "s/.*/'&'/" | \
	${XARGS} -n 256 ${LS} -ld 2>/dev/null |				\
	${AWK} 'BEGIN { s = 0 } { s += $$5 } END { print s }'		\
		> ${.TARGET}

######################################################################
###
### +CONTENTS - Package manifest file
###
### This file contains the list of files and checksums, along with
### any special "@" commands, e.g. @dirrm.
###
_CONTENTS_FILE=		${PKG_DB_TMPDIR}/+CONTENTS
_METADATA_TARGETS+=	${_CONTENTS_FILE}

_PKG_CREATE_ARGS+=				-v -l -U
_PKG_CREATE_ARGS+=				-B ${_BUILD_INFO_FILE}
_PKG_CREATE_ARGS+=				-b ${_BUILD_VERSION_FILE}
_PKG_CREATE_ARGS+=				-c ${_COMMENT_FILE}
_PKG_CREATE_ARGS+=	${_MESSAGE_FILE:D	-D ${_MESSAGE_FILE}}
_PKG_CREATE_ARGS+=				-d ${_DESCR_FILE}
_PKG_CREATE_ARGS+=				-f ${PLIST}
_PKG_CREATE_ARGS+=	${NO_MTREE:D:U		-m ${_MTREE_FILE}}
_PKG_CREATE_ARGS+=	${PKG_PRESERVE:D	-n ${_PRESERVE_FILE}}
_PKG_CREATE_ARGS+=				-S ${_SIZE_ALL_FILE}
_PKG_CREATE_ARGS+=				-s ${_SIZE_PKG_FILE}
_PKG_CREATE_ARGS+=	${CONFLICTS:D		-C ${CONFLICTS:Q}}
_PKG_CREATE_ARGS+=				${_DEPENDS_ARG_cmd:sh}
.if ${PKGTOOLS_VERSION} >= 20070308
_PKG_CREATE_ARGS+=				${_BUILD_DEPENDS_ARG_cmd:sh}
.endif
_PKG_CREATE_ARGS+=	${INSTALL_FILE:D	${_INSTALL_ARG_cmd:sh}}
_PKG_CREATE_ARGS+=	${DEINSTALL_FILE:D	${_DEINSTALL_ARG_cmd:sh}}

_PKG_ARGS_INSTALL+=	${_PKG_CREATE_ARGS}
.if ${_USE_DESTDIR} == "no"
_PKG_ARGS_INSTALL+=	-p ${PREFIX}
.else
_PKG_ARGS_INSTALL+=	-I ${PREFIX} -p ${DESTDIR}${PREFIX}
.endif

_DEPENDS_ARG_cmd=	depends=`${_DEPENDS_PATTERNS_CMD}`;		\
			if ${TEST} -n "$$depends"; then			\
				${ECHO} "-P \"$$depends\"";		\
			else						\
				${ECHO};				\
			fi

_BUILD_DEPENDS_ARG_cmd=	depends=`${_BUILD_DEPENDS_PATTERNS_CMD}`;	\
			if ${TEST} -n "$$depends"; then			\
				${ECHO} "-T \"$$depends\"";		\
			else						\
				${ECHO};				\
			fi

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

_CONTENTS_TARGETS+=	${_BUILD_INFO_FILE}
_CONTENTS_TARGETS+=	${_BUILD_VERSION_FILE}
_CONTENTS_TARGETS+=	${_COMMENT_FILE}
_CONTENTS_TARGETS+=	${_COOKIE.depends}
_CONTENTS_TARGETS+=	${_DESCR_FILE}
_CONTENTS_TARGETS+=	${_MESSAGE_FILE}
_CONTENTS_TARGETS+=	plist
_CONTENTS_TARGETS+=	${_PRESERVE_FILE}
_CONTENTS_TARGETS+=	${_SIZE_ALL_FILE}
_CONTENTS_TARGETS+=	${_SIZE_PKG_FILE}
_CONTENTS_TARGETS+=	${NO_MTREE:D:U${_MTREE_FILE}}

${_CONTENTS_FILE}: ${_CONTENTS_TARGETS}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${PKG_CREATE} ${_PKG_ARGS_INSTALL} -O ${PKGFILE:T} > ${.TARGET}

######################################################################
### generate-metadata (PRIVATE)
######################################################################
### generate-metadata is a convenience target for generating all of
### the pkgsrc binary package meta-data files.  It populates
### ${PKG_DB_TMPDIR} with the following files:
###
###	+BUILD_INFO
###	+BUILD_VERSION
###	+COMMENT
###	+CONTENTS
###	+DESC
###	+DISPLAY
###	+PRESERVE
###	+SIZE_ALL
###	+SIZE_PKG
###
### See the targets above for descriptions of each of those files.
###
.PHONY: generate-metadata
generate-metadata: ${_METADATA_TARGETS}

######################################################################
### clean-metadata (PRIVATE)
######################################################################
### clean-metadata is a convenience target for removing the meta-data
### directory.
###
.PHONY: clean-metadata
clean-metadata:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -fr ${PKG_DB_TMPDIR}
