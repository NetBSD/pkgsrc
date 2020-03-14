# $NetBSD: pkg-build-options.mk,v 1.13 2020/03/14 10:32:30 rillig Exp $
#
# This procedure determines the PKG_OPTIONS that have been in effect
# when the package ${pkgbase} has been built. When the package is not
# yet installed, its current PKG_OPTIONS are queried.
#
# Parameters:
#	pkgbase
#		The package identifier, as in the package's buildlink3.mk
#		file.
#
# Returns:
#	PKG_BUILD_OPTIONS.${pkgbase}
#		The build options of the package.
#
# Example:
#	.include "../../emulators/wine/buildlink3.mk"
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
_BUILDLINK_TREE_WITH:=	${BUILDLINK_TREE:M-*:[\#]}
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
.    if !defined(PKG_BUILD_OPTIONS.${b}) && defined(PBULK_CACHE_DIRECTORY)
.sinclude "${PBULK_CACHE_DIRECTORY}/build-options.${b}"
.    endif
.    if !defined(PKG_BUILD_OPTIONS.${b})
PKG_BUILD_OPTIONS.${b}!= \
	echo ""; \
	${PKG_INFO} -Q PKG_OPTIONS ${b} 2>/dev/null \
	|| { cd ${BUILDLINK_PKGSRCDIR.${b}} \
	     && ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKG_OPTIONS; }
.        if defined(PBULK_CACHE_DIRECTORY)
_PKG_BUILD_OPTIONS.${b}!= \
	mkdir -p ${PBULK_CACHE_DIRECTORY:Q}; \
	echo PKG_BUILD_OPTIONS.${b:Q}=${PKG_BUILD_OPTIONS.${b:Q}} > ${PBULK_CACHE_DIRECTORY:Q}/build-options.${pkgbase}.$$$$; \
	mv ${PBULK_CACHE_DIRECTORY:Q}/build-options.${pkgbase}.$$$$ ${PBULK_CACHE_DIRECTORY:Q}/build-options.${pkgbase}
.        endif
MAKEFLAGS+=	PKG_BUILD_OPTIONS.${b}=${PKG_BUILD_OPTIONS.${b}:Q}
.    endif

MAKEVARS+=	PKG_BUILD_OPTIONS.${b}
.  endfor
.endif
