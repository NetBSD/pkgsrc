# $NetBSD: Makefile,v 1.71 2020/04/12 08:29:05 adam Exp $

DISTNAME=	gupnp-tools-0.8.9
PKGREVISION=	31
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-tools/0.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

BUILDLINK_API_DEPENDS.gupnp+= gupnp>=0.20.8
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
