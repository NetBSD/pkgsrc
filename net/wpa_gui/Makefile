# $NetBSD: Makefile,v 1.5 2008/04/07 18:25:38 joerg Exp $

DISTNAME=	wpa_supplicant-0.4.9
PKGNAME=	${DISTNAME:S/supplicant/gui/}
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	QT GUI for wpa_supplicant(8)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
BUILD_TARGET=	wpa_gui
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_gui/wpa_gui ${DESTDIR}${PREFIX}/sbin

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
