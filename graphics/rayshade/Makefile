# $NetBSD: Makefile,v 1.13 2004/12/03 15:14:59 wiz Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/05/26 04:04:11 mph Exp
#

DISTNAME=	rayshade.4.0
PKGNAME=	rayshade-4.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Extensible system for creating ray-traced images

DEPENDS+=	urt>=3.1b1nb1:../../graphics/urt

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	< ${WRKDIR}/config.ans
BUILD_TARGET=

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

.include "../../mk/bsd.pkg.mk"
