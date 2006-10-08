# $NetBSD: bsd.package.mk,v 1.8 2006/10/08 20:31:38 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to binary packages.
#
# The following are the "public" targets provided by this module:
#
#    package, repackage
#
# The following variables may be set by the package:
#
# MAKE_PACKAGE_AS_ROOT: YesNo
#	When this variable is set to "no", the package is created by
#	the user that also built the package. Since most packages don't
#	need root privileges to create the package, the default value
#	is "no". Packages that install unreadable files (for example
#	with mode 4111) need to set this variable to "yes".
#
#	Default value: "yes", but this will change to "no" after most
#	packages that really need this option have been identified.

MAKE_PACKAGE_AS_ROOT?=	yes

_COOKIE.package=	${WRKDIR}/.package_done

######################################################################
### package (PUBLIC)
######################################################################
### package is a public target to generate a binary package.
###
.PHONY: package
.if !defined(NO_PACKAGE)
.  include "${PKGSRCDIR}/mk/package/package.mk"
.elif !target(package)
.  if exists(${_COOKIE.package})
package:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
package: install
.    if defined(SKIP_SILENT)
	@${DO_NADA}
.    else
	@${PHASE_MSG} "${PKGNAME} may not be packaged: "${NO_PACKAGE:Q}"."
.    endif
.  else
package: barrier
.  endif
.endif

######################################################################
### repackage (PUBLIC)
######################################################################
### repackage is a special target to re-run the package target.
###
.PHONY: repackage
.if !target(repackage)
repackage: package-clean package
.endif

######################################################################
### package-clean (PRIVATE)
######################################################################
### package-clean removes the state files associated with the "package"
### phase so that the "package" target may be re-invoked.
###
package-clean:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_COOKIE.package}
