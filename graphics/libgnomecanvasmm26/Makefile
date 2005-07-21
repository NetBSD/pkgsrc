# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:51 wiz Exp $
#

DISTNAME=		libgnomecanvasmm-2.6.1
PKGNAME=		libgnomecanvasmm26-2.6.1
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomecanvasmm/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for libgnomecanvas

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomecanvas/libgnomecanvasmm-2.6.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
