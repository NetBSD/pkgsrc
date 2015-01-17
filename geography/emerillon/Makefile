# $NetBSD: Makefile,v 1.33 2015/01/17 14:36:11 prlw1 Exp $
#

DISTNAME=	emerillon-0.1.2
PKGREVISION=	28
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/emerillon/0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/emerillon/
COMMENT=	Map browser

BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config intltool gmake msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
#CONFIGURE_ARGS+=	--disable-search
GCONF_SCHEMAS=		emerillon.schemas
#PKGCONFIG_OVERRIDE=	data/emerillon.pc.in

CONFIGURE_ARGS+=	VALAC=${VALAC}

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED

BUILDLINK_DEPMETHOD.vala?=	build

.include "../../devel/GConf/schemas.mk"
.include "../../devel/ethos/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../geography/libchamplain06/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../www/librest/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
