# $NetBSD: Makefile,v 1.22 2006/01/24 07:32:02 wiz Exp $

DISTNAME=	gconfmm-2.12.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gconfmm/2.12/}
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

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
