# $NetBSD: pkg-build-options.mk,v 1.4 2007/08/11 16:25:16 rillig Exp $
#
# This procedure determines the PKG_OPTIONS that have been in effect
# when the package ${pkgbase} has been built. When the package is not
# yet installed, the current PKG_OPTIONS are queried.
#
# Parameters:
#	pkgbase
#		The basename of the package.
#	pkgpath
#		The directory in which the source package lives.
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
	echo ""; \
	${PKG_INFO} -Q PKG_OPTIONS ${pkgbase} 2>/dev/null \
	|| { cd ${BUILDLINK_PKGSRCDIR.${b}} \
	     && ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKG_OPTIONS; }

MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor

.elif defined(bl4_package) && defined(pkgpath)
.  for b in ${bl4_package}
.    if !defined(PKG_BUILD_OPTIONS.${b})
.      if ${pkgpath} == ${PKGPATH}
PKG_BUILD_OPTIONS.${b} = ${PKG_OPTIONS}
.      else
PKG_BUILD_OPTIONS.${b} != \
	${PKG_INFO} -Q PKG_OPTIONS ${b} 2>/dev/null \
	|| { cd ${PKGSRCDIR}/${pkgpath} \
	     && ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKG_OPTIONS; }

MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.      endif
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor

.else
.  for b in ${pkgbase}
PKG_FAIL_REASON+=	"[pkg-build-options.mk] This file may only be included from a buildlink3.mk file (pkgbase=${b})."
.  endfor
.endif
