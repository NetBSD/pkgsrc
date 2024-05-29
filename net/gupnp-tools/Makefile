# $NetBSD: Makefile,v 1.92 2024/05/29 16:33:54 adam Exp $

DISTNAME=	gupnp-tools-0.12.1
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-tools/${PKGVERSION_NOREV:R}//}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror=deprecated-declarations

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/meson/build.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
