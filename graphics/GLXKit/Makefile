# $NetBSD: Makefile,v 1.18 2009/07/07 05:46:52 joerg Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	13

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

MAKE_FLAGS+=	ADDITIONAL_INCLUDE_DIRS=-I${BUILDLINK_PREFIX.RenderKit}/System/Library/Headers
MAKE_FLAGS+=	ADDITIONAL_LIB_DIRS="-L${BUILDLINK_PREFIX.RenderKit}/System/Library/Libraries -Wl,-rpath,${BUILDLINK_PREFIX.RenderKit}/System/Library/Libraries"

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
