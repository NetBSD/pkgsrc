# $NetBSD: Makefile,v 1.54 2013/02/16 11:19:26 wiz Exp $

DISTNAME=	gconfmm-2.28.3
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gconfmm/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for gconf

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gconf/gconfmm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
