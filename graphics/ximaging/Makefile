# $NetBSD: Makefile,v 1.6 2023/10/21 17:10:44 gdt Exp $

DISTNAME=	ximaging-src-1.7
PKGNAME=	${DISTNAME:S,-src,,}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Image browser and viewer for Unix - X/Motif
LICENSE=	mit

# Enable support for OpenMP, Xinerama and various image formats.
CFLAGS+=	-fopenmp -DENABLE_JPEG -DENABLE_PNG -DENABLE_OMP \
		-DENABLE_PNG -DENABLE_TIFF -DENABLE_XINERAMA
LDFLAGS+=	-fopenmp

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
BUILDLINK_TRANSFORM+=	rm:-pthread

MAKE_FLAGS+=	CC?=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	PNG_LIBS=-lpng16
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	APPLRESDIR=${PREFIX}/lib/X11/app-defaults

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	lib/X11/app-defaults

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ximaging ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/ximaging.1					\
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/XImaging.ad				\
	${DESTDIR}${PREFIX}/lib/X11/app-defaults/XImaging

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
