# $NetBSD: Makefile,v 1.126 2020/06/02 08:22:56 adam Exp $

PKGREVISION=		43

PKGCONFIG_OVERRIDE=	gnome-vfs-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-vfs-module-2.0.pc.in

OWN_DIRS=		${PKG_SYSCONFDIR}/modules

EGFILES+=		modules/default-modules.conf
EGFILES+=		modules/ssl-modules.conf

GCONF_SCHEMAS=	desktop_default_applications.schemas
GCONF_SCHEMAS+=	desktop_gnome_url_handlers.schemas
GCONF_SCHEMAS+=	system_dns_sd.schemas
GCONF_SCHEMAS+=	system_http_proxy.schemas
GCONF_SCHEMAS+=	system_smb.schemas

LDFLAGS.Darwin+=	-lresolv

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.3

MAKE_JOBS_SAFE=		no

.include "Makefile.common"
.include "options.mk"

CONFLICTS+=		gnome-vfs2-[0-9]*
CONFLICTS+=		gnome-vfs-dns-sd-[0-9]*

.include "../../devel/GConf/schemas.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
