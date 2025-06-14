# $NetBSD: Makefile,v 1.79 2025/06/14 01:14:51 gutteridge Exp $

VERSION=	0.13.4
DISTNAME=	ristretto-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	https://archive.xfce.org/src/apps/ristretto/${VERSION:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/applications/ristretto
COMMENT=	Xfce image viewer
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake autoreconf
USE_TOOLS+=		gmake pkg-config msgfmt gdbus-codegen

LDFLAGS.DragonFly=	-lX11
LDFLAGS.FreeBSD=	-lX11
LDFLAGS.SunOS=		-lX11

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.56.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
