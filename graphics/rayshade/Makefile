# $NetBSD: Makefile,v 1.16 2005/06/16 06:57:59 jlam Exp $

DISTNAME=	rayshade.4.0
PKGNAME=	rayshade-4.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Extensible system for creating ray-traced images

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	< ${WRKDIR}/config.ans
BUILD_TARGET=
INSTALLATION_DIRS=	bin lib

pre-configure:
	${SED} -e 's|@CFLAGS@|${CFLAGS}|g' 			\
		-e 's|\$${PREFIX}|${PREFIX}|g'			\
		-e 's|\$${LOCALBASE}|${LOCALBASE}|g'			\
		${FILESDIR}/config.ans > ${WRKDIR}/config.ans

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rayshade/rayshade ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libray/libray.a ${PREFIX}/lib
	${RANLIB} ${PREFIX}/lib/libray.a
	${INSTALL_DATA} ${WRKSRC}/libshade/libshade.a ${PREFIX}/lib
	${RANLIB} ${PREFIX}/lib/libshade.a
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Doc/Guide/* ${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Doc/quickref.txt ${PREFIX}/share/doc/rayshade
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rayshade
	${INSTALL_DATA} ${WRKSRC}/Examples/* ${PREFIX}/share/examples/rayshade

.include "../../graphics/urt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
