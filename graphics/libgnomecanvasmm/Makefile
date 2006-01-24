# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:16 wiz Exp $

DISTNAME=	libgnomecanvasmm-2.12.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomecanvasmm/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnomecanvas

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomecanvas/libgnomecanvasmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
