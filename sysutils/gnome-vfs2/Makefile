# $NetBSD: Makefile,v 1.18 2003/12/04 19:48:25 xtraeme Exp $
#

DISTNAME=		gnome-vfs-2.2.4
PKGNAME=		${DISTNAME:S/vfs/vfs2/}
PKGREVISION=		6
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System (v2)

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gnome-vfs-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-vfs-module-2.0.pc.in

CONFIGURE_ARGS= 	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--enable-platform-gnome-2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0
OWN_DIRS=		${PKG_SYSCONFDIR}/modules ${PKG_SYSCONFDIR}/vfolders

EGDIR=		${PREFIX}/share/examples/gnome-vfs-2.0
EGFILES=	modules/default-modules.conf
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

GCONF2_SCHEMAS=	system_http_proxy.schemas

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
