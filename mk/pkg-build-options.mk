# $NetBSD: pkg-build-options.mk,v 1.9 2012/12/17 14:27:44 wiz Exp $
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
# Keywords: options pkg-build-options PKG_BUILD_OPTIONS
#

.include "bsd.fast.prefs.mk"

# For the check for inclusion from non-buildlink3.mk, it is irrelevant
# whether BUILDLINK_TREE was empty or undefined, so defining it here
# avoids dealing one case.
BUILDLINK_TREE?=

# Counting words doesn't work as expected for empty strings, they
# still have one word.  Older make doesn't like the code without
# variable assignment for unknown reasons.
_BUILDLINK_TREE_WITH:= ${BUILDLINK_TREE:M-*:[\#]}
_BUILDLINK_TREE_WITHOUT:= ${BUILDLINK_TREE:N-*:[\#]}
.if (empty(BUILDLINK_TREE:M-*) && empty(BUILDLINK_TREE:N-*)) || \
    (!empty(BUILDLINK_TREE:M-*) && !empty(BUILDLINK_TREE:N-*) && \
     ${_BUILDLINK_TREE_WITH} == ${_BUILDLINK_TREE_WITHOUT})
.  for b in ${pkgbase}
PKG_BUILD_OPTIONS.${b}=
PKG_FAIL_REASON+=	"[pkg-build-options.mk] This file may only be included from a buildlink3.mk file (pkgbase=${b})."
.  endfor
.else
.  for b in ${pkgbase}
.    if !defined(PKG_BUILD_OPTIONS.${b})
PKG_BUILD_OPTIONS.${b} != \
	echo ""; \
	${PKG_INFO} -Q PKG_OPTIONS ${b} 2>/dev/null \
	|| { cd ${BUILDLINK_PKGSRCDIR.${b}} \
	     && ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKG_OPTIONS; }

MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor
.endif
