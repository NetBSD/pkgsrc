# $NetBSD: Makefile,v 1.8 2025/01/31 10:09:43 wiz Exp $

DISTNAME=	WordTsar-0.3.719-src
PKGNAME=	${DISTNAME:tl:S/-src//}
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wordtsar/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://wordtsar.ca/
COMMENT=	Wordstar for the 21st Century
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	bash pkg-config
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

REPLACE_BASH+=	rev.sh

# unclear why this is necessary or where this comes from
SUBST_CLASSES+=		path
SUBST_SED.path+=	-e s,../../src/core/include/version.h,../src/core/include/version.h,
SUBST_FILES.path+=	build/Makefile
SUBST_STAGE.path=	post-configure
SUBST_MESSAGE.path=	Fixing path to version.h

do-configure:
	${MKDIR} ${WRKSRC}/build
	${CHMOD} 755 ${WRKSRC}/rev.sh
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
