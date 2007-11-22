# $NetBSD: Makefile,v 1.30 2007/11/22 11:19:57 adam Exp $

DISTNAME=	gconfmm-2.20.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gconfmm/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for gconf

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gconf/gconfmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
