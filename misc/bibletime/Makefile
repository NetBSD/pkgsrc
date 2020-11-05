# $NetBSD: Makefile,v 1.51 2020/11/05 09:08:39 ryoon Exp $

DISTNAME=		bibletime-2.11.2
PKGREVISION=		11
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bibletime/}
EXTRACT_SUFX=		.tar.xz
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bibletime.info/
COMMENT=		Bible study program based on SWORD and QT
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		docdir
SUBST_FILES.docdir=	${WRKSRC}/cmake/BTDocumentation.cmake
SUBST_FILES.docdir+=	${WRKSRC}/src/util/directory.cpp
SUBST_STAGE.docdir=	pre-configure
SUBST_SED.docdir=	-e 's,bibletime/docs,doc/bibletime,g'

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../misc/sword/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
