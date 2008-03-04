# $NetBSD: Makefile,v 1.17 2008/03/04 15:39:09 jlam Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	13

DISTFILES=	DevManual.pdf

COMMENT=	Objective-C 3D graphics foundation class library

NO_CONFIGURE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/3DKit
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${DESTDIR}${PREFIX}/share/doc/3DKit

.include "../../graphics/GlutKit/buildlink3.mk"
.include "../../graphics/GLXKit/buildlink3.mk"
.include "../../graphics/SDLKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
