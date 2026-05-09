# $NetBSD: Makefile,v 1.73 2026/05/09 16:36:31 vins Exp $

DISTNAME=	gnome-online-accounts-3.58.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeOnlineAccounts
COMMENT=	Service that allows online accounts to be used with GNOME
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		gdbus-codegen pkg-config
USE_PKGLOCALEDIR=	yes

# required to generate man pages
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DOCBOOK_MANPAGE_XSL=	${PREFIX}/share/xsl/docbook/manpages/docbook.xsl

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	doc/meson.build
SUBST_VARS.man+=	DOCBOOK_MANPAGE_XSL

MESON_ARGS+=		--localedir=${PKGLOCALEDIR}/locale

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/goa-1.0.pc \
				output/meson-private/goa-backend-1.0.pc

.for dep in gobject-introspection vala
BUILDLINK_DEPMETHOD.${dep}=	build
.endfor

.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/gcr4/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../www/librest/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
