# $NetBSD: gap.package.mk,v 1.3 2002/12/22 16:06:33 cjep Exp $
#
# Set GAP_PKG_NAME in your Makefile. More may appear here later.

# Note that between nb1 == bug fix 3 and nb2 == bug fix 4 there are
# some interface changes

DEPENDS+=       	gap-4.3nb2:../../math/gap
GAP_DIRECTORY=  	${LOCALBASE}/lib/gap4.3
GAP_PKG_DIRECTORY=	${GAP_DIRECTORY}/pkg/${GAP_PKG_NAME}
