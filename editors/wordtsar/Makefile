# $NetBSD: Makefile,v 1.17 2026/11/09 17:35:45 ryoon Exp $

DISTNAME=	wordtsar-0.5.1850-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wordtsar/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wordtsar.ca/
COMMENT=	Wordstar for the 21st Century
LICENSE=	gnu-agpl-v3

DISTFILES=	${DEFAULT_DISTFILES}

KUBA=		zip-0.3.15-miniz.3.1.2.tar.gz
DISTFILES+=	${KUBA}
SITES.${KUBA}=	-https://github.com/kuba--/zip/archive/refs/tags/v0.3.15+miniz.3.1.2.tar.gz

SINI=		simpleini-4.27.tar.gz
DISTFILES+=	${SINI}
SITES.${SINI}=	-https://github.com/brofield/simpleini/archive/refs/tags/v4.27.tar.gz

STB=		stb-0.0.0-4e9b368bfc071e97206ea5c6adba68dd0cbf8897.tar.gz
DISTFILES+=	${STB}
SITES.${STB}=	-https://github.com/nothings/stb/archive/4e9b368bfc071e97206ea5c6adba68dd0cbf8897.tar.gz

ETK=		exprtk-0.0.3.tar.gz
DISTFILES+=	${ETK}
SITES.${ETK}=	-https://github.com/ArashPartow/exprtk/archive/refs/tags/0.0.3.tar.gz

PMT=		picomath-1.1.0.tar.gz
DISTFILES+=	${PMT}
SITES.${PMT}=	-https://github.com/Nitrillo/picomath/archive/refs/tags/v1.1.0.tar.gz

HARU=		libharu-2.4.6.tar.gz
DISTFILES+=	${HARU}
SITES.${HARU}=	-https://github.com/libharu/libharu/archive/refs/tags/v2.4.6.tar.gz

CPPU=		cpp-unicodelib-18.0.0.tar.gz
DISTFILES+=	${CPPU}
SITES.${CPPU}=	-https://github.com/yhirose/cpp-unicodelib/archive/refs/tags/v18.0.0.tar.gz

PUGI=		pugixml-1.16.tar.gz
DISTFILES+=	${PUGI}
SITES.${PUGI}=	https://github.com/zeux/pugixml/releases/download/v1.16/

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CFLAGS+=	-DZIP_HAVE_SYMLINK=1

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

BUILDLINK_TRANSFORM+=	l:hunspell:hunspell-1.7
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

post-extract:
	${MV} ${WRKDIR}/zip-0.3.15-miniz.3.1.2 ${WRKSRC}/third-party/zip
	${MV} ${WRKDIR}/cpp-unicodelib-18.0.0 ${WRKSRC}/third-party/cpp-unicodelib
	${MV} ${WRKDIR}/exprtk-0.0.3 ${WRKSRC}/third-party/exprtk
	${MV} ${WRKDIR}/libharu-2.4.6 ${WRKSRC}/third-party/libharu
	${MV} ${WRKDIR}/picomath-1.1.0 ${WRKSRC}/third-party/picomath
	${MV} ${WRKDIR}/pugixml-1.16 ${WRKSRC}/third-party/pugixml
	${MV} ${WRKDIR}/simpleini-4.27 ${WRKSRC}/third-party/simpleini
	${MV} ${WRKDIR}/stb-4e9b368bfc071e97206ea5c6adba68dd0cbf8897 ${WRKSRC}/third-party/stb

	${FIND} ${WRKSRC} -name '*.orig' | xargs ${RM} -f

.include "../../devel/cmake/build.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
