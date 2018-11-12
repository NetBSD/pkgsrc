# $NetBSD: Makefile,v 1.4 2018/11/12 03:52:56 ryoon Exp $

DISTNAME=	qdirstat-1.0
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=shundhammer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shundhammer/qdirstat/
COMMENT=	Qt-based directory statistics
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

REPLACE_PERL+=	scripts/qdirstat-cache-writer

#SUBST_CLASSES+=			filemanager
#SUBST_STAGE.filemanager=	post-patch
#SUBST_MESSAGE.filemanager=	Use dolphin not konqueror
#SUBST_FILES.filemanager=	src/Cleanup.cpp
#SUBST_SED.filemanager=		-e 's:konqueror --profile filemanagement:dolphin:'

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

do-configure:
	cd ${WRKSRC} && qmake

INSTALLATION_DIRS= bin share/applications share/pixmaps share/doc/qdirstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qdirstat ${DESTDIR}${PREFIX}/bin/qdirstat
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/qdirstat-cache-writer ${DESTDIR}${PREFIX}/bin/qdirstat-cache-writer
	${INSTALL_DATA} ${WRKSRC}/src/qdirstat.desktop ${DESTDIR}${PREFIX}/share/applications/qdirstat.desktop
	${INSTALL_DATA} ${WRKSRC}/src/icons/qdirstat.png ${DESTDIR}${PREFIX}/share/pixmaps/qdirstat.png
	cd ${WRKSRC} && ${INSTALL_DATA} Contributing.md DevHistory.md README.md TODO.md LICENSE ${DESTDIR}${PREFIX}/share/doc/qdirstat/

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
