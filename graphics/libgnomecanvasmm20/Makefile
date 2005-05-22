# $NetBSD: Makefile,v 1.5 2005/05/22 20:08:06 jlam Exp $
#

DISTNAME=		libgnomecanvasmm-2.0.2
PKGNAME=		libgnomecanvasmm20-2.0.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomecanvasmm/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for libgnomecanvas

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomecanvas/libgnomecanvasmm-2.0.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
# gtkmm must be 2.0/2.2
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
