# $NetBSD: package.mk,v 1.16 2017/08/19 00:30:19 jlam Exp $

.if defined(PKG_SUFX)
WARNINGS+=		"PKG_SUFX is deprecated, please use PKG_COMPRESSION"
.  if ${PKG_SUFX} == ".tgz"
PKG_COMPRESSION=	gzip
.  elif ${PKG_SUFX} == ".tbz"
PKG_COMPRESSION=	bzip2
.  else
WARNINGS+=		"Unsupported value for PKG_SUFX"
.  endif
.endif
PKG_SUFX?=		.tgz
FILEBASE?=		${PKGBASE}
PKGFILE?=		${PKGREPOSITORY}/${FILEBASE}-${PKGVERSION}${PKG_SUFX}
STAGE_PKGFILE?=		${WRKDIR}/.packages/${FILEBASE}-${PKGVERSION}${PKG_SUFX}
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
PKGREPOSITORYSUBDIR?=	All

######################################################################
### package-create (PRIVATE, pkgsrc/mk/package/package.mk)
######################################################################
### package-create creates the binary package.
###
.PHONY: package-create
package-create: ${PKGFILE}

######################################################################
### stage-package-create (PRIVATE, pkgsrc/mk/package/package.mk)
######################################################################
### stage-package-create creates the binary package for stage install.
###
.PHONY: stage-package-create
stage-package-create:	stage-install ${STAGE_PKGFILE}

_PKG_ARGS_PACKAGE+=	${_PKG_CREATE_ARGS}
_PKG_ARGS_PACKAGE+=	-F ${PKG_COMPRESSION}
_PKG_ARGS_PACKAGE+=	-I ${PREFIX} -p ${DESTDIR}${PREFIX}
.if ${_USE_DESTDIR} == "user-destdir"
_PKG_ARGS_PACKAGE+=	-u ${REAL_ROOT_USER} -g ${REAL_ROOT_GROUP}
.endif

${STAGE_PKGFILE}: ${_CONTENTS_TARGETS}
	@${STEP_MSG} "Creating binary package ${.TARGET}"
	${RUN} ${MKDIR} ${.TARGET:H}; ${_ULIMIT_CMD}			\
	tmpname=${.TARGET:S,${PKG_SUFX}$,.tmp${PKG_SUFX},};		\
	if ! ${PKG_CREATE} ${_PKG_ARGS_PACKAGE} "$$tmpname"; then	\
		exitcode=$$?; ${RM} -f "$$tmpname"; exit $$exitcode;	\
	fi
.if !empty(SIGN_PACKAGES:U:Mgpg)
	@${STEP_MSG} "Signing binary package ${.TARGET} (GPG)"
	${RUN} tmpname=${.TARGET:S,${PKG_SUFX}$,.tmp${PKG_SUFX},};	\
	${PKG_ADMIN} gpg-sign-package "$$tmpname" ${.TARGET}
.elif !empty(SIGN_PACKAGES:U:Mx509)
	@${STEP_MSG} "Signing binary package ${.TARGET} (X509)"
	${RUN} tmpname=${.TARGET:S,${PKG_SUFX}$,.tmp${PKG_SUFX},};	\
	${PKG_ADMIN} x509-sign-package "$$tmpname" ${.TARGET}		\
		${X509_KEY} ${X509_CERTIFICATE}
.else
	${RUN} tmpname=${.TARGET:S,${PKG_SUFX}$,.tmp${PKG_SUFX},};	\
	${MV} -f "$$tmpname" ${.TARGET}
.endif

.if ${PKGFILE} != ${STAGE_PKGFILE}
${PKGFILE}: ${STAGE_PKGFILE}
	@${STEP_MSG} "Creating binary package ${.TARGET}"
	${RUN} ${MKDIR} ${.TARGET:H};					\
	${LN} -f ${STAGE_PKGFILE} ${PKGFILE} 2>/dev/null ||		\
		${CP} -pf ${STAGE_PKGFILE} ${PKGFILE}
.endif

######################################################################
### package-remove (PRIVATE)
######################################################################
### package-remove removes the binary package from the package
### repository.
###
.PHONY: package-remove
package-remove:
	${RUN} ${RM} -f ${PKGFILE}

######################################################################
### stage-package-remove (PRIVATE)
######################################################################
### stage-package-remove removes the binary package for stage install
###
.PHONY: stage-package-remove
stage-package-remove:
	${RUN} ${RM} -f ${STAGE_PKGFILE}

######################################################################
### tarup (PUBLIC)
######################################################################
### tarup is a public target to generate a binary package from an
### installed package instance.
###
_PKG_TARUP_CMD= ${LOCALBASE}/bin/pkg_tarup

.PHONY: tarup
tarup: package-remove tarup-pkg

######################################################################
### tarup-pkg (PRIVATE)
######################################################################
### tarup-pkg creates a binary package from an installed package instance
### using "pkg_tarup".
###
tarup-pkg:
	${RUN} [ -x ${_PKG_TARUP_CMD} ] || exit 1;			\
	${PKGSRC_SETENV} PKG_DBDIR=${_PKG_DBDIR} PKG_SUFX=${PKG_SUFX}	\
		PKGREPOSITORY=${PKGREPOSITORY}				\
		${_PKG_TARUP_CMD} -f ${FILEBASE} ${PKGNAME}

######################################################################
### package-install (PUBLIC)
######################################################################
### When DESTDIR support is active, package-install uses package to
### create a binary package and installs it.
### Otherwise it is identical to calling package.
###

.PHONY: package-install real-package-install su-real-package-install
.if defined(_PKGSRC_BARRIER)
package-install: package real-package-install
.else
package-install: barrier
.endif

.PHONY: stage-package-install
.if defined(_PKGSRC_BARRIER)
stage-package-install: stage-package-create real-package-install
.else
stage-package-install: barrier
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
real-package-install: su-real-package-install
.else
real-package-install: su-target
.endif

MAKEFLAGS.su-real-package-install=	PKGNAME_REQD=${PKGNAME_REQD:Q}
su-real-package-install:
	@${PHASE_MSG} "Installing binary package of "${PKGNAME:Q}
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
	@${MKDIR} ${_CROSS_DESTDIR}${PREFIX}
	${SETENV} ${PKGTOOLS_ENV} ${PKG_ADD} -m ${MACHINE_ARCH} -I -p ${_CROSS_DESTDIR}${PREFIX} ${STAGE_PKGFILE}
	@${ECHO} "Fixing recorded cwd..."
	@${SED} -e 's|@cwd ${_CROSS_DESTDIR}|@cwd |' ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS > ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp
	@${MV} ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS
.else
	${RUN} case ${_AUTOMATIC:Q}"" in					\
	[yY][eE][sS])								\
		${SETENV} ${PKGTOOLS_ENV} ${PKG_ADD} -A ${STAGE_PKGFILE} ;;	\
	*)	${SETENV} ${PKGTOOLS_ENV} ${PKG_ADD} ${STAGE_PKGFILE} ;;	\
	esac
.endif
