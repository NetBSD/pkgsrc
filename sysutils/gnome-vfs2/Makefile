# $NetBSD: Makefile,v 1.34 2004/04/01 18:21:20 jmmv Exp $
#

DISTNAME=		gnome-vfs-2.6.0
PKGNAME=		${DISTNAME:S/vfs/vfs2/}
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System (v2)

BUILD_USES_MSGFMT=	YES
DEPENDS+=		shared-mime-info>=0.13:../../databases/shared-mime-info

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES

PKGCONFIG_OVERRIDE=	gnome-vfs-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-vfs-module-2.0.pc.in

CONFIGURE_ARGS= 	--disable-gtk
CONFIGURE_ARGS+= 	--disable-samba
CONFIGURE_ARGS+=	--enable-platform-gnome-2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ENV+=		openssl_libs="yes"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia
CPPFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"
CPPFLAGS+=		-DPKGLOCALEDIR=\"\\\"${PKGLOCALEDIR}\\\"\"

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0
OWN_DIRS=		${PKG_SYSCONFDIR}/modules ${PKG_SYSCONFDIR}/vfolders

EGDIR=		${PREFIX}/share/examples/gnome-vfs-2.0
EGFILES=	modules/cdda-module.conf
EGFILES+=	modules/default-modules.conf
EGFILES+=	modules/ssl-modules.conf
EGFILES+=	vfolders/applications-all-users.vfolder-info
EGFILES+=	vfolders/favorites.vfolder-info
EGFILES+=	vfolders/network.vfolder-info
EGFILES+=	vfolders/preferences-all-users.vfolder-info
EGFILES+=	vfolders/server-settings.vfolder-info
EGFILES+=	vfolders/start-here.vfolder-info
EGFILES+=	vfolders/system-settings.vfolder-info
.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

GCONF2_SCHEMAS=		desktop_default_applications.schemas
GCONF2_SCHEMAS+=	desktop_gnome_url_handlers.schemas
GCONF2_SCHEMAS+=	system_http_proxy.schemas
GCONF2_SCHEMAS+=	system_smb.schemas

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
