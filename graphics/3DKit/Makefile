# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 06:12:51 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

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
