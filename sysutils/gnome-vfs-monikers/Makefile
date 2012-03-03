# $NetBSD: Makefile,v 1.16 2012/03/03 00:13:57 wiz Exp $
#

DISTNAME=	gnome-vfs-monikers-2.15.3
PKGREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-vfs-monikers/2.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	VFS namespace moniker for Bonobo

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
