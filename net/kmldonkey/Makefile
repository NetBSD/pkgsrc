# $NetBSD: Makefile,v 1.39 2016/03/05 11:29:06 jperkin Exp $
#

DISTNAME=	kmldonkey-2.0.2-kde4.4.0
PKGNAME=	${DISTNAME:S/-kde/./}
PKGREVISION=	32
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_KDE:=4.4.0/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://userbase.kde.org/KMLDonkey
COMMENT=	KDE4 interface for mldonkey
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
