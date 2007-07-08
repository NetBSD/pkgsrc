# $NetBSD: Makefile,v 1.4 2007/07/08 12:35:11 wiz Exp $

DISTNAME=	wpa_supplicant-0.4.9
PKGNAME=	${DISTNAME:S/supplicant/gui/}
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	QT GUI for wpa_supplicant(8)

USE_LANGUAGES=	c c++
BUILD_TARGET=	wpa_gui
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_gui/wpa_gui ${PREFIX}/sbin/wpa_gui

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
