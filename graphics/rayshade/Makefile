# $NetBSD: Makefile,v 1.20 2006/06/08 21:40:21 joerg Exp $

DISTNAME=	rayshade.4.0
PKGNAME=	rayshade-4.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=	Extensible system for creating ray-traced images

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
BUILD_TARGET=
INSTALLATION_DIRS=	bin lib share/doc/rayshade share/examples/rayshade

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rayshade/rayshade ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libray/libray.a ${PREFIX}/lib
	${RANLIB} ${PREFIX}/lib/libray.a
	${INSTALL_DATA} ${WRKSRC}/libshade/libshade.a ${PREFIX}/lib
	${RANLIB} ${PREFIX}/lib/libshade.a
	${INSTALL_DATA} ${WRKSRC}/Doc/Guide/* ${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Doc/quickref.txt ${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Examples/* ${PREFIX}/share/examples/rayshade

.include "../../graphics/urt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
