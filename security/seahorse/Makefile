# $NetBSD: Makefile,v 1.162 2020/11/22 12:04:28 nia Exp $

DISTNAME=	seahorse-3.38.0.1
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/3.38/}
CATEGORIES=	security gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Seahorse
COMMENT=	GNOME encryption interface
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS+=	pkg-config msgfmt xgettext

# Why does it want specific point releases?
MESON_ARGS+=	-Dcheck-compatible-gpg=false

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- xml
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libpwquality/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
