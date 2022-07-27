# $NetBSD: Makefile,v 1.61 2022/07/27 01:15:44 gutteridge Exp $

VERSION=	0.12.3
DISTNAME=	ristretto-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	https://archive.xfce.org/src/apps/ristretto/${VERSION:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/applications/ristretto
COMMENT=	Xfce image viewer
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt perl intltool gdbus-codegen

LDFLAGS.DragonFly=	-lX11
LDFLAGS.FreeBSD=	-lX11
LDFLAGS.SunOS=		-lX11

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.16.0
.include "../../x11/libxfce4util/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.16.0
.include "../../x11/libxfce4ui/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
