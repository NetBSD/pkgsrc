# $NetBSD: Makefile,v 1.109 2018/11/14 22:22:15 kleink Exp $

DISTNAME=	vino-2.32.2
PKGREVISION=	39
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vino/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	VNC server for GNOME
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gnome-keyring
CONFIGURE_ARGS+=	--enable-http-server=yes

GCONF_SCHEMAS=		vino-server.schemas

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
