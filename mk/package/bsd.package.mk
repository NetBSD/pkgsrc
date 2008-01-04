# $NetBSD: bsd.package.mk,v 1.10 2008/01/04 01:46:27 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to binary packages.
#
# The following are the "public" targets provided by this module:
#
#    package, repackage

_COOKIE.package=	${WRKDIR}/.package_done

######################################################################
### package (PUBLIC)
######################################################################
### package is a public target to generate a binary package.
###
.PHONY: package
.if !defined(NO_PACKAGE)
.  include "package.mk"
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
