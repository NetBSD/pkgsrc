# $NetBSD: package.mk,v 1.16 2008/01/23 14:07:07 rillig Exp $

PKG_SUFX?=		.tgz
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
PKGREPOSITORYSUBDIR?=	All

######################################################################
### package-check-installed (PRIVATE, pkgsrc/mk/package/package.mk)
######################################################################
### package-check-installed verifies that the package is installed on
### the system.
###
.PHONY: package-check-installed
package-check-installed:
	${RUN} ${PKG_INFO} -qe ${PKGNAME} \
	|| ${FAIL_MSG} "${PKGNAME} is not installed."

######################################################################
### package-create (PRIVATE, pkgsrc/mk/package/package.mk)
######################################################################
### package-create creates the binary package.
###
.PHONY: package-create
package-create: package-remove ${PKGFILE} package-links

_PKG_ARGS_PACKAGE+=	${_PKG_CREATE_ARGS}
.if ${_USE_DESTDIR} == "no"
_PKG_ARGS_PACKAGE+=	-p ${PREFIX}
.else
_PKG_ARGS_PACKAGE+=	-I ${PREFIX} -p ${DESTDIR}${PREFIX}
.  if ${_USE_DESTDIR} == "user-destdir"
_PKG_ARGS_PACKAGE+=	-u ${REAL_ROOT_USER} -g ${REAL_ROOT_GROUP}
.  endif
.endif
_PKG_ARGS_PACKAGE+=	-L ${DESTDIR}${PREFIX}			# @src ...
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_PKG_ARGS_PACKAGE+=	-E
.endif

${PKGFILE}: ${_CONTENTS_TARGETS}
	${RUN} ${MKDIR} ${.TARGET:H}
	@${STEP_MSG} "Creating binary package ${.TARGET}"
	${RUN} tmpname=${.TARGET:S,${PKG_SUFX}$,.tmp${PKG_SUFX},};	\
	if ${PKG_CREATE} ${_PKG_ARGS_PACKAGE} "$$tmpname"; then		\
		${MV} -f "$$tmpname" ${.TARGET};			\
	else								\
		exitcode=$$?; ${RM} -f "$$tmpname"; exit $$exitcode;	\
	fi

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
### package-links (PRIVATE)
######################################################################
### package-links creates symlinks to the binary package from the
### non-primary categories to which the package belongs.
###
package-links: delete-package-links
.for _dir_ in ${CATEGORIES:S/^/${PACKAGES}\//}
	${RUN} ${MKDIR} ${_dir_:Q}
	${RUN} [ -d ${_dir_:Q} ]					\
	|| ${FAIL_MSG} "Can't create directory "${_dir_:Q}"."
	${RUN} ${RM} -f ${_dir_:Q}/${PKGFILE:T}
	${RUN} ${LN} -s ../${PKGREPOSITORYSUBDIR}/${PKGFILE:T} ${_dir_:Q}
.endfor

######################################################################
### delete-package-links (PRIVATE)
######################################################################
### delete-package-links removes the symlinks to the binary package from
### the non-primary categories to which the package belongs.
###
delete-package-links:
	${RUN} ${FIND} ${PACKAGES} -type l -name ${PKGFILE:T} -print	\
	| ${XARGS} ${RM} -f

######################################################################
### tarup (PUBLIC)
######################################################################
### tarup is a public target to generate a binary package from an
### installed package instance.
###
_PKG_TARUP_CMD= ${LOCALBASE}/bin/pkg_tarup

.PHONY: tarup
tarup: package-remove tarup-pkg package-links

######################################################################
### tarup-pkg (PRIVATE)
######################################################################
### tarup-pkg creates a binary package from an installed package instance
### using "pkg_tarup".
###
tarup-pkg:
	${RUN} [ -x ${_PKG_TARUP_CMD} ] || exit 1;			\
	${SETENV} PKG_DBDIR=${_PKG_DBDIR} PKG_SUFX=${PKG_SUFX}		\
		PKGREPOSITORY=${PKGREPOSITORY}				\
		${_PKG_TARUP_CMD} ${PKGNAME}

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

.if ${_USE_DESTDIR} != "no"
.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
real-package-install: su-real-package-install
.  else
real-package-install: su-target
.  endif
.else
real-package-install:
	@${DO_NADA}
.endif

su-real-package-install:
	@${PHASE_MSG} "Install binary package of "${PKGNAME:Q}
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
	@${MKDIR} ${_CROSS_DESTDIR}${PREFIX}
	${PKG_ADD} -m ${MACHINE_ARCH} -I -p ${_CROSS_DESTDIR}${PREFIX} ${PKGFILE}
	@${ECHO} "Fixing recorded cwd..."
	@${SED} -e 's|@cwd ${_CROSS_DESTDIR}|@cwd |' ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS > ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp
	@${MV} ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS
.else
	${PKG_ADD} ${PKGFILE}
.endif
