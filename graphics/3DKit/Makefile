# $NetBSD: Makefile,v 1.15 2007/10/14 05:26:21 rillig Exp $
#

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	12

DISTFILES=	DevManual.pdf

COMMENT=	Objective-C 3D graphics foundation class library

NO_CONFIGURE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/3DKit
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} ${PREFIX}/share/doc/3DKit

.include "../../graphics/GlutKit/buildlink3.mk"
.include "../../graphics/GLXKit/buildlink3.mk"
.include "../../graphics/SDLKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
