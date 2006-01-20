# $NetBSD: Makefile,v 1.27 2006/01/20 15:09:01 jmmv Exp $
#

DISTNAME=	nautilus-cd-burner-2.12.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-cd-burner/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CD burner view for Nautilus

DEPENDS+=		{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools
BUILD_USES_MSGFMT=	yes
USE_MSGFMT_PLURALS=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libnautilus-burn.pc.in

CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INSTALL_MAKE_FLAGS+=	modulesconfdir=${PREFIX}/share/examples/nautilus-cd-burner/gnome-vfs-2.0/modules
INSTALL_MAKE_FLAGS+=	schemadir=${GCONF2_SCHEMAS_DIR}

CPPFLAGS+=		-D__unix__

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/nautilus-cd-burner/gnome-vfs-2.0/modules
CONF_FILES=		${EGDIR}/mapping-modules.conf \
			${PKG_SYSCONFDIR}/mapping-modules.conf

GCONF2_SCHEMAS=		ncb.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
