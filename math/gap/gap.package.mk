# $NetBSD: gap.package.mk,v 1.9 2003/12/18 14:44:17 sketch Exp $
#
# Set GAP_PKG_NAME in your Makefile. More may appear here later.

# Note that between nb1 == bug fix 3 and nb2 == bug fix 4 there are
# some interface changes

DEPENDS+=       	gap>=4.3nb6:../../math/gap
GAP_DIRECTORY=  	${LOCALBASE}/lib/gap4.3
GAP_PKG_ROOT=		${GAP_DIRECTORY}/pkg
GAP_PKG_DIRECTORY=	${GAP_PKG_ROOT}/${GAP_PKG_NAME}
GAP_PLATFORM=   	${MACHINE_GNU_PLATFORM}-cc

PLIST_SUBST=    GAP_PLATFORM=${GAP_PLATFORM}
