# $NetBSD: gap.package.mk,v 1.14 2007/02/22 19:26:47 wiz Exp $
#
# Set GAP_PKG_NAME in your Makefile. More may appear here later.

# Note that between 4.3nb1 == bug fix 3 and 4.3nb2 == bug fix 4 there are
# some interface changes

DEPENDS+=	gap>=4.3.5:../../math/gap
GAP_DIRECTORY=	${LOCALBASE}/lib/gap4.3
GAP_PKG_ROOT=		${GAP_DIRECTORY}/pkg
GAP_PKG_DIRECTORY=	${GAP_PKG_ROOT}/${GAP_PKG_NAME}
GAP_PLATFORM=	${MACHINE_GNU_PLATFORM}-${CC}

PLIST_SUBST+=		GAP_PLATFORM=${GAP_PLATFORM:Q}
