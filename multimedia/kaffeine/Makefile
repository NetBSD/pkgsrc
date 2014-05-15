# $NetBSD: Makefile,v 1.48 2014/05/15 14:41:56 adam Exp $
#

DISTNAME=	kaffeine-1.2.2
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kaffeine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kaffeine.kde.org/
COMMENT=	Full featured Multimedia-Player for KDE4
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	msgfmt
USE_LANGUAGES=	c c++

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
