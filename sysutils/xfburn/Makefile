# $NetBSD: Makefile,v 1.21 2023/01/29 21:17:51 ryoon Exp $

VERSION=	0.6.2
DISTNAME=	xfburn-${VERSION}
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/apps/xfburn/${VERSION:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfburn
COMMENT=	Simple CD/DVD burning program for Xfce
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libburn/buildlink3.mk"
.include "../../sysutils/libisofs/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
