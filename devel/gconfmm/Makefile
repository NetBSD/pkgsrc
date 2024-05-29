# $NetBSD: Makefile,v 1.83 2024/05/29 16:32:01 adam Exp $

DISTNAME=	gconfmm-2.28.3
PKGREVISION=	34
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gconfmm/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
#HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ bindings for gconf

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gconf/gconfmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
