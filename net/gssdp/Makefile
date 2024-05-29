# $NetBSD: Makefile,v 1.109 2024/05/29 16:33:53 adam Exp $

DISTNAME=	gssdp-1.6.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gssdp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GUPnP
COMMENT=	Simple Service Discovery Protocol library and device sniffer
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

# needs pandoc
MESON_ARGS+=	-Dmanpages=false
# needs GTK3+
MESON_ARGS+=	-Dsniffer=false

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=		output/meson-private/gssdp-1.6.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libgssdp
# for Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/libgssdp

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.54.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
