# $NetBSD: Makefile,v 1.9 2005/12/11 09:40:44 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	7

DISTFILES=	DevManual.pdf

COMMENT=	Objective-C 3D graphics foundation class library

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/3DKit
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}	\
		${PREFIX}/share/doc/3DKit

.include "../../graphics/GlutKit/buildlink3.mk"
.include "../../graphics/GLXKit/buildlink3.mk"
.include "../../graphics/SDLKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
