# $NetBSD: Makefile,v 1.3 2004/01/03 18:49:41 reed Exp $
#

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	2

DISTFILES=	DevManual.pdf

COMMENT=	Objective-C 3D graphics foundation class library

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/3DKit
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}	\
		${PREFIX}/share/doc/3DKit

.include "../../graphics/GlutKit/buildlink2.mk"
.include "../../graphics/GLXKit/buildlink2.mk"
.include "../../graphics/SDLKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
