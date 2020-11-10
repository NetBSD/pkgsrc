# $NetBSD: Makefile,v 1.1 2020/11/10 12:34:04 nia Exp $

DISTNAME=	gnome-screenshot-3.38.0
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
CATEGORIES=	graphics gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-screenshot
COMMENT=	Screenshot capture utility for GNOME
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
