# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:15 tv Exp $
#

DISTNAME=		gnome-vfsmm-2.6.1
PKGNAME=		gnome-vfsmm26-2.6.1
PKGREVISION=	1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfsmm/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for gnome-vfs

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomevfs/gnome-vfsmm-2.6.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
