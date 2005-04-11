# $NetBSD: Makefile,v 1.16 2005/04/11 21:45:21 tv Exp $
#

DISTNAME=	gconfmm-2.0.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gconfmm/2.0/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to GConf2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	gconf/gconfmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/gconfmm-2.0-uninstalled.pc.in

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
# gtkmm must be 2.0/2.2
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
