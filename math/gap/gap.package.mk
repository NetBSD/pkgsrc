# $NetBSD: gap.package.mk,v 1.4 2002/12/22 17:40:03 cjep Exp $
#
# Set GAP_PKG_NAME in your Makefile. More may appear here later.

# Note that between nb1 == bug fix 3 and nb2 == bug fix 4 there are
# some interface changes

DEPENDS+=       	gap-4.3nb3:../../math/gap
GAP_DIRECTORY=  	${LOCALBASE}/lib/gap4.3
GAP_PKG_ROOT=		${GAP_DIRECTORY}/pkg
GAP_PKG_DIRECTORY=	${GAP_PKG_ROOT}/${GAP_PKG_NAME}
