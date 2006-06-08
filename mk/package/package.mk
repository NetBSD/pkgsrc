# $NetBSD: package.mk,v 1.5 2006/06/08 15:48:42 jlam Exp $

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

.if !exists(${_PACKAGE_COOKIE})
${_PACKAGE_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-package PKG_PHASE=package
.else
${_PACKAGE_COOKIE}:
	@${DO_NADA}
.endif

######################################################################
### real-package (PRIVATE)
######################################################################
### real-package is a helper target to set the PKG_PHASE explicitly to
### "package" before running the remainder of the package targets.
###
_REAL_PACKAGE_TARGETS+=	package-message
_REAL_PACKAGE_TARGETS+=	package-all
_REAL_PACKAGE_TARGETS+=	package-cookie

.PHONY: real-package
real-package: ${_REAL_PACKAGE_TARGETS}

.PHONY: package-message
package-message:
	@${PHASE_MSG} "Building binary package for ${PKGNAME}"

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
	@${WARNING_MSG} "${PKGNAME} may not be put on a CD-ROM:"
	@${WARNING_MSG} ${NO_BIN_ON_CDROM:Q}
.endif
.if defined(NO_BIN_ON_FTP)
	@${WARNING_MSG} "${PKGNAME} may not be made available through FTP:"
	@${WARNING_MSG} ${NO_BIN_ON_FTP:Q}
.endif
.if defined(ABI_DEPENDS) && !empty(USE_ABI_DEPENDS:M[Nn][Oo])
	@${WARNING_MSG} "ABI dependency recommendations are being ignored!"
	@${WARNING_MSG} "${PKGNAME} should not be uploaded nor"
	@${WARNING_MSG} "otherwise be used as a binary package!"
.endif
