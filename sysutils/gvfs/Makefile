# $NetBSD: Makefile,v 1.10 2008/10/24 21:48:44 wiz Exp $
#

DISTNAME=	gvfs-1.0.2
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
