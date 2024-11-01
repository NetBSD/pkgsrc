# $NetBSD: Makefile,v 1.3 2024/11/01 00:51:39 wiz Exp $

DISTNAME=	WordTsar-0.3.719-src
PKGNAME=	${DISTNAME:tl:S/-src//}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wordtsar/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://wordtsar.ca/
COMMENT=	Wordstar for the 21st Century
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-configure:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && \
		${CONFIGURE_ENV} ${QTDIR}/bin/qmake ../wordtsar.pro

do-build:
	cd ${WRKSRC}/build && \
		${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/WordTsar \
		${DESTDIR}${PREFIX}/bin

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
