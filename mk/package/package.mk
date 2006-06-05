# $NetBSD: package.mk,v 1.2 2006/06/05 17:41:11 jlam Exp $

_PACKAGE_COOKIE=	${WRKDIR}/.package_done

######################################################################
### package (PUBLIC)
######################################################################
### package is a public target to generate a binary package.  It will
### acquire elevated privileges just-in-time.
###
_PACKAGE_TARGETS+=	install
_PACKAGE_TARGETS+=	acquire-package-lock
_PACKAGE_TARGETS+=	${_PACKAGE_COOKIE}
_PACKAGE_TARGETS+=	release-package-lock

.PHONY: package
.if !target(package)
package: ${_PACKAGE_TARGETS}
.endif

.PHONY: acquire-package-lock release-package-lock
acquire-package-lock: acquire-lock
release-package-lock: release-lock

${_PACKAGE_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-package PKG_PHASE=package

######################################################################
### real-package (PRIVATE)
######################################################################
### real-package is a helper target to set the PKG_PHASE explicitly to
### "package" before running the remainder of the package targets.
###
.PHONY: real-package
real-package: package-message package-all package-cookie

.PHONY: package-message
package-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Building binary package for ${PKGNAME}"

######################################################################
### package-cookie (PRIVATE)
######################################################################
### package-cookie creates the "package" cookie file
###
.PHONY: package-cookie
package-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} >> ${_PACKAGE_COOKIE}

######################################################################
### The targets below are run with elevated privileges.
######################################################################

######################################################################
### package-all, su-package-all (PRIVATE)
######################################################################
### package-all is a helper target to create the binary package and
### generate any necessary warnings.
###
_PACKAGE_ALL_TARGETS+=	package-check-installed
_PACKAGE_ALL_TARGETS+=	package-create
_PACKAGE_ALL_TARGETS+=	package-warnings

.PHONY: package-all su-package-all
package-all: su-target
su-package-all: ${_PACKAGE_ALL_TARGETS}

######################################################################
### package-check-installed (PRIVATE, override)
######################################################################
### package-check-installed verifies that the package is installed on
### the system.  This should be overridden per package system flavor.
###
.if !target(package-check-installed)
.PHONY: package-check-installed
package-check-installed:
	@${DO_NADA}
.endif

######################################################################
### package-create (PRIVATE, override)
######################################################################
### package-create creates the binary package.  This should be overridden
### per package system flavor.
###
.if !target(package-create)
.PHONY: package-create
package-create:
	@${DO_NADA}
.endif

######################################################################
### package-warnings (PRIVATE)
######################################################################
### package-warnings displays warnings about the binary package.
###
.PHONY: package-warnings
package-warnings:
.if defined(NO_BIN_ON_CDROM)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be put on a CD-ROM:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_CDROM:Q}
.endif
.if defined(NO_BIN_ON_FTP)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be made available through FTP:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_FTP:Q}
.endif
.if defined(ABI_DEPENDS) && !empty(USE_ABI_DEPENDS:M[Nn][Oo])
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ABI dependency recommendations are being ignored!"
	@${ECHO_MSG} "${_PKGSRC_IN}>          ${PKGNAME} should not be uploaded nor"
	@${ECHO_MSG} "${_PKGSRC_IN}>          otherwise be used as a binary package!"
.endif
