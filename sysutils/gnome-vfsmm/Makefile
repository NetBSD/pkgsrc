# $NetBSD: Makefile,v 1.16 2007/10/13 17:44:12 adam Exp $

DISTNAME=	gnome-vfsmm-2.20.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-vfsmm/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for gnome-vfs

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomevfs/gnome-vfsmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glibmm/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
