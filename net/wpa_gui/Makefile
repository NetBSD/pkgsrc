# $NetBSD: Makefile,v 1.1.1.1 2006/10/22 23:20:21 rpaulo Exp $

DISTNAME=	wpa_supplicant-0.4.9
PKGNAME=	${DISTNAME:S/supplicant/gui/}
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	QT GUI for wpa_supplicant(8)

USE_LANGUAGES+=	c++
BUILD_TARGET=	wpa_gui
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_gui/wpa_gui ${PREFIX}/sbin/wpa_gui

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
