# $NetBSD: Makefile,v 1.2 2008/04/15 16:34:28 drochner Exp $
#

DISTNAME=	gvfs-0.2.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Userspace virtual filesystem

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool gmake
CONFIGURE_ARGS+=	--with-samba-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-samba-libs=${LOCALBASE}/lib/samba

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
