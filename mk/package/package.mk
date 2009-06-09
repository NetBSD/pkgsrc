# $NetBSD: package.mk,v 1.21 2009/06/09 08:40:28 joerg Exp $
#
# This file provides the code for the "package" phase.
#
# Public targets:
#
# package:
#	Generates a binary package.
#	It will acquire elevated privileges just-in-time.
#
#	XXX: From which files is the binary package generated? The
#	installed files in LOCALBASE, or some files in WRKDIR/.destdir?
#

_PACKAGE_TARGETS+=	check-vulnerable
.if make(replace) && ${_USE_DESTDIR} == "no"
_PACKAGE_TARGETS+=	replace
.else
_PACKAGE_TARGETS+=	install
.endif
_PACKAGE_TARGETS+=	acquire-package-lock
_PACKAGE_TARGETS+=	${_COOKIE.package}
_PACKAGE_TARGETS+=	release-package-lock

.PHONY: package
.if !target(package)
.  if exists(${_COOKIE.package})
package:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
package: ${_PACKAGE_TARGETS}
.  else
package: barrier
.  endif
.endif

.PHONY: acquire-package-lock release-package-lock
acquire-package-lock: acquire-lock
release-package-lock: release-lock

.if exists(${_COOKIE.package})
${_COOKIE.package}:
	@${DO_NADA}
.else
${_COOKIE.package}: real-package
.endif

######################################################################
### real-package (PRIVATE)
######################################################################
### real-package is a helper target onto which one can hook all of the
### targets that do the actual packaging of the built objects.
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
	${RUN} ${TEST} ! -f ${_COOKIE.package} || ${FALSE}
	${RUN} ${MKDIR} ${_COOKIE.package:H}
	${RUN} ${ECHO} ${PKGNAME} > ${_COOKIE.package}

######################################################################
### The targets below are run with elevated privileges.
######################################################################

######################################################################
### package-all, su-package-all (PRIVATE)
######################################################################
### package-all is a helper target to create the binary package and
### generate any necessary warnings.
###
.if ${_USE_DESTDIR} == "no"
_PACKAGE_ALL_TARGETS+=	package-check-installed
.endif
_PACKAGE_ALL_TARGETS+=	package-create
_PACKAGE_ALL_TARGETS+=	_package-warnings
_PACKAGE_ALL_TARGETS+=	error-check

.PHONY: package-all su-package-all
.if !empty(_MAKE_PACKAGE_AS_ROOT:M[Yy][Ee][Ss])
package-all: su-target
.else
package-all: su-package-all
.endif
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

# Displays warnings about the binary package.
#
_package-warnings: .PHONY
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
