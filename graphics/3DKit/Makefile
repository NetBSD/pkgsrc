# $NetBSD: Makefile,v 1.7 2004/09/24 01:56:54 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"
PKGREVISION=	5

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
