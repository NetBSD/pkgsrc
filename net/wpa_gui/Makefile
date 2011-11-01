# $NetBSD: Makefile,v 1.12 2011/11/01 06:02:23 sbd Exp $

DISTNAME=	wpa_supplicant-0.7.3
PKGNAME=	${DISTNAME:S/supplicant/gui/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	QT GUI for wpa_supplicant(8)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
BUILD_DIRS=	wpa_supplicant
BUILD_TARGET=	wpa_gui
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_supplicant/wpa_gui/wpa_gui ${DESTDIR}${PREFIX}/sbin

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
