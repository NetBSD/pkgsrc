# $NetBSD: Makefile,v 1.5 2010/02/15 15:31:38 wiz Exp $
#

DISTNAME=	kmldonkey-2.0.2-kde4.3.3
PKGNAME=	${DISTNAME:S/-kde/./}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_KDE:=4.3.3/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://userbase.kde.org/KMLDonkey
COMMENT=	KDE4 interface for mldonkey
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	msgfmt

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
