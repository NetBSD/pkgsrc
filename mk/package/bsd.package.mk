# $NetBSD: bsd.package.mk,v 1.14 2010/03/08 13:51:24 joerg Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to binary packages.
#
# The following are the "public" targets provided by this module:
#
#    package, repackage, package-clean

_COOKIE.package=	${WRKDIR}/.package_done

######################################################################
### package (PUBLIC)
######################################################################
### package is a public target to generate a binary package.
###
.PHONY: package
.include "package.mk"

######################################################################
### repackage (PUBLIC)
######################################################################
### repackage is a special target to re-run the package target.
###
.PHONY: repackage
.if !target(repackage)
repackage: package-eat-cookie package
.endif

######################################################################
### package-clean (PUBLIC)
######################################################################
### package-clean removes the binary package that has been created
### by the "package" phase.
### Also remove the cookie, so that the "package" target can be
### invoked again.
###
.PHONY: package-clean
package-clean: package-eat-cookie
	${RUN} ${RM} -f ${PKGFILE}

######################################################################
### package-eat-cookie (PRIVATE)
######################################################################
### package-eat-cookie removes the state files associated with the "package"
### phase so that the "package" target may be re-invoked.
###
package-eat-cookie:
	${RUN} ${RM} -f ${_COOKIE.package}
