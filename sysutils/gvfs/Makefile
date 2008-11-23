# $NetBSD: Makefile,v 1.11 2008/11/23 03:28:50 jmcneill Exp $
#

DISTNAME=	gvfs-1.0.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Userspace virtual filesystem

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool gmake pkg-config msgfmt
CONFIGURE_ARGS+=	--with-samba-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-samba-libs=${LOCALBASE}/lib/samba
CONFIGURE_ARGS+=	--enable-http

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=        PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+= hal
PKG_SUGGESTED_OPTIONS+= hal
PLIST_VARS+=		hal
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
PLIST.hal=		yes
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.24

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
