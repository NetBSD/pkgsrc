# $NetBSD: Makefile,v 1.43 2005/01/11 12:32:53 jmmv Exp $
#

PKGREVISION=		1

PKGCONFIG_OVERRIDE=	gnome-vfs-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-vfs-module-2.0.pc.in

OWN_DIRS=		${PKG_SYSCONFDIR}/modules ${PKG_SYSCONFDIR}/vfolders

EGFILES+=		modules/default-modules.conf
EGFILES+=		modules/ssl-modules.conf
EGFILES+=		vfolders/applications-all-users.vfolder-info
EGFILES+=		vfolders/favorites.vfolder-info
EGFILES+=		vfolders/network.vfolder-info
EGFILES+=		vfolders/preferences-all-users.vfolder-info
EGFILES+=		vfolders/server-settings.vfolder-info
EGFILES+=		vfolders/start-here.vfolder-info
EGFILES+=		vfolders/system-settings.vfolder-info

GCONF2_SCHEMAS=		desktop_default_applications.schemas
GCONF2_SCHEMAS+=	desktop_gnome_url_handlers.schemas
GCONF2_SCHEMAS+=	system_dns_sd.schemas
GCONF2_SCHEMAS+=	system_http_proxy.schemas
GCONF2_SCHEMAS+=	system_smb.schemas

CFLAGS.Darwin+=		-flat_namespace -undefined suppress -lresolv

.include "Makefile.common"

.include "../../devel/GConf2/schemas.mk"
.include "../../sysutils/fam/buildlink3.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
