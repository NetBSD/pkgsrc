# $NetBSD: Makefile,v 1.53 2008/01/18 05:09:44 tnn Exp $
#

DISTNAME=	nautilus-cd-burner-2.14.3
PKGREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-cd-burner/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CD burner view for Nautilus

DEPENDS+=		{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	libnautilus-burn.pc.in

CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	modulesconfdir=${PREFIX}/share/examples/nautilus-cd-burner/gnome-vfs-2.0/modules
INSTALL_MAKE_FLAGS+=	schemadir=${GCONF_SCHEMAS_DIR}

CPPFLAGS+=		-D__unix__

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/nautilus-cd-burner/gnome-vfs-2.0/modules
CONF_FILES=		${EGDIR}/mapping-modules.conf \
			${PKG_SYSCONFDIR}/mapping-modules.conf

GCONF_SCHEMAS=		ncb.schemas

BUILDLINK_API_DEPENDS.eel+=	eel>=2.13.3
BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.13.4

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/eel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
