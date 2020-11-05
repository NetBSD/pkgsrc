# $NetBSD: Makefile,v 1.76 2020/11/05 09:06:50 ryoon Exp $

DISTNAME=	libgnomemm-2.30.0
PKGREVISION=	41
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomemm/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
#HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnome

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnome/libgnomemm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
