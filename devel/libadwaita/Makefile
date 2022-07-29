# $NetBSD: Makefile,v 1.1 2022/07/29 16:34:58 wiz Exp $

DISTNAME=	libadwaita-1.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libadwaita/1.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libadwaita/
COMMENT=	Building blocks for modern GNOME applications
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt pkg-config

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- xml
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PKGCONFIG_OVERRIDE+=	output/meson-private/libadwaita-1.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
