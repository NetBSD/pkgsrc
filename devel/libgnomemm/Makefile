# $NetBSD: Makefile,v 1.21 2009/01/12 15:43:12 wiz Exp $

DISTNAME=	libgnomemm-2.24.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomemm/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnome

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnome/libgnomemm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
