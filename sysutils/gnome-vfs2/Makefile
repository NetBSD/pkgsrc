# $NetBSD: Makefile,v 1.72 2007/04/29 13:09:27 tnn Exp $

PKGREVISION=		1
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

LDFLAGS.Darwin+=	-lresolv

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-fam

.include "../../devel/GConf2/schemas.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/fam.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
