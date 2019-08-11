# $NetBSD: Makefile,v 1.47 2019/08/11 13:23:08 wiz Exp $
#

DISTNAME=		gnome-system-tools-2.22.2
PKGREVISION=		41
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-system-tools/2.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		System administraton tools for the GNOME desktop

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-system-tools
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mhal)
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.endif

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GCONF_SCHEMAS+=		gnome-system-tools.schemas

#fix symlink problems when primary source figure is not in 'C' directory root
#may be overkill (only nl needs this) but it avoids `pkg_admin check` errors
post-extract:
	${CP} ${WRKSRC}/doc/services/nl/figures/service-properties.png \
			${WRKSRC}/doc/services/C/figures/

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/liboobs/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
