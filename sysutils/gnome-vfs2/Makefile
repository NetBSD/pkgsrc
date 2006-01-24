# $NetBSD: Makefile,v 1.55 2006/01/24 07:32:34 wiz Exp $

PKGCONFIG_OVERRIDE=	gnome-vfs-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-vfs-module-2.0.pc.in

OWN_DIRS=		${PKG_SYSCONFDIR}/modules

EGFILES+=		modules/default-modules.conf
EGFILES+=		modules/ssl-modules.conf

GCONF2_SCHEMAS=		desktop_default_applications.schemas
GCONF2_SCHEMAS+=	desktop_gnome_url_handlers.schemas
GCONF2_SCHEMAS+=	system_dns_sd.schemas
GCONF2_SCHEMAS+=	system_http_proxy.schemas
GCONF2_SCHEMAS+=	system_smb.schemas
GCONF2_SCHEMAS+=	system_storage.schemas

LDFLAGS.Darwin+=	-lresolv

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0

.include "Makefile.common"
PKGREVISION=	1

.include "../../devel/GConf2/schemas.mk"

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

.include "../../mk/fam.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
