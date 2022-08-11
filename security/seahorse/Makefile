# $NetBSD: Makefile,v 1.175 2022/08/11 05:09:13 gutteridge Exp $

DISTNAME=	seahorse-3.38.0.1
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/3.38/}
PKGREVISION=	8
CATEGORIES=	security gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Seahorse
COMMENT=	GNOME encryption interface
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext itstool
USE_TOOLS+=	gdbus-codegen

# Why does it want specific point releases?
MESON_ARGS+=	-Dcheck-compatible-gpg=false

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
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
