# $NetBSD: Makefile,v 1.39 2016/06/01 13:31:49 joerg Exp $

DISTNAME=	rayshade.4.0.6
PKGNAME=	rayshade-4.0.6
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extensible system for creating ray-traced images

# lex output racy
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
USE_TOOLS+=		lex yacc
BUILD_TARGET=
INSTALLATION_DIRS=	bin lib share/doc/rayshade share/examples/rayshade
WRKSRC=		${WRKDIR}/rayshade.4.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rayshade/rayshade ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libray/libray.a ${DESTDIR}${PREFIX}/lib
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libray.a
	${INSTALL_DATA} ${WRKSRC}/libshade/libshade.a ${DESTDIR}${PREFIX}/lib
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libshade.a
	${INSTALL_DATA} ${WRKSRC}/Doc/Guide/* \
		${DESTDIR}${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Doc/quickref.txt \
		${DESTDIR}${PREFIX}/share/doc/rayshade
	${INSTALL_DATA} ${WRKSRC}/Examples/* \
		${DESTDIR}${PREFIX}/share/examples/rayshade

.include "../../graphics/urt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
