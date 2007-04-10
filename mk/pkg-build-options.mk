# $NetBSD: pkg-build-options.mk,v 1.2 2007/04/10 03:45:36 rillig Exp $
#
# This procedure determines the PKG_OPTIONS that have been in effect
# when the package ${pkgbase} has been built. When the package is not
# yet installed, the current PKG_OPTIONS are queried.
#
# Parameters:
#	pkgbase
#		The basename of the package.
#
# Returns:
#	PKG_BUILD_OPTIONS.${pkgbase}
#		The build options of the package.
#
# Example:
#	pkgbase := wine
#	.include "../../mk/pkg-build-options.mk"
#
# TODO: Query the installed package if it exists.
#

.if defined(BUILDLINK_DEPTH) && !empty(BUILDLINK_DEPTH)
.  for b in ${pkgbase}
.    if !defined(PKG_BUILD_OPTIONS.${b})
PKG_BUILD_OPTIONS.${b} != \
	cd ${BUILDLINK_PKGSRCDIR.${b}} \
	&& ${MAKE} ${MAKEFLAGS} \
		show-var VARNAME=PKG_OPTIONS

MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor
.else
.  for b in ${pkgbase}
PKG_FAIL_REASON+=	"[pkg-build-options.mk] This file may only be included from a buildlink3.mk file (pkgbase=${b})."
.  endfor
.endif
