# $NetBSD: Makefile,v 1.22 2018/11/12 03:52:57 ryoon Exp $

DISTNAME=	tarsnap-gui-1.0
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tarsnap/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Tarsnap/tarsnap-gui
COMMENT=	Cross-platform GUI for the Tarsnap backup service
LICENSE=	2-clause-bsd

DEPENDS+=	tarsnap-[0-9]*:../../sysutils/tarsnap

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tarsnap-gui ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
