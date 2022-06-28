# $NetBSD: Makefile,v 1.27 2022/06/28 11:36:04 wiz Exp $

DISTNAME=	qdirstat-1.8
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=shundhammer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shundhammer/qdirstat/
COMMENT=	Qt-based directory statistics
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

REPLACE_PERL+=	scripts/qdirstat-cache-writer

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

do-configure:
	cd ${WRKSRC} && qmake

INSTALLATION_DIRS=	bin share/applications share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qdirstat ${DESTDIR}${PREFIX}/bin/qdirstat
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/qdirstat-cache-writer ${DESTDIR}${PREFIX}/bin/qdirstat-cache-writer
	${INSTALL_DATA} ${WRKSRC}/src/qdirstat.desktop ${DESTDIR}${PREFIX}/share/applications/qdirstat.desktop
	${INSTALL_DATA} ${WRKSRC}/src/icons/qdirstat.png ${DESTDIR}${PREFIX}/share/pixmaps/qdirstat.png

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
