# $NetBSD: pkg-build-options.mk,v 1.3 2007/05/07 09:26:40 rillig Exp $
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

.include "${.PARSEDIR}/bsd.fast.prefs.mk"

.if defined(BUILDLINK_DEPTH) && !empty(BUILDLINK_DEPTH)
.  for b in ${pkgbase}
.    if !defined(PKG_BUILD_OPTIONS.${b})
PKG_BUILD_OPTIONS.${b} != \
	${PKG_INFO} -Q PKG_OPTIONS ${pkgbase} 2>/dev/null \
	|| { cd ${BUILDLINK_PKGSRCDIR.${b}} \
	     && ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKG_OPTIONS; }

MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor
.else
.  for b in ${pkgbase}
PKG_FAIL_REASON+=	"[pkg-build-options.mk] This file may only be included from a buildlink3.mk file (pkgbase=${b})."
.  endfor
.endif
