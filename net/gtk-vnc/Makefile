# $NetBSD: Makefile,v 1.111 2024/05/16 06:15:19 wiz Exp $

DISTNAME=	gtk-vnc-1.3.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-vnc/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gtk-vnc
COMMENT=	VNC viewer widget for GTK
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/*.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

MESON_ARGS+=		-D with-coroutine=gthread

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.11
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
