# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:03 wiz Exp $

DISTNAME=	libgnomemm-2.12.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomemm/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnome

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnome/libgnomemm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
