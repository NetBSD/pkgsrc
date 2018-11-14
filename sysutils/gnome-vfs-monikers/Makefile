# $NetBSD: Makefile,v 1.44 2018/11/14 22:22:25 kleink Exp $
#

DISTNAME=	gnome-vfs-monikers-2.15.3
PKGREVISION=	40
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-vfs-monikers/2.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	VFS namespace moniker for Bonobo

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
