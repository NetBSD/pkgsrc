# $NetBSD: Makefile,v 1.13 2004/03/09 20:56:35 minskim Exp $
#

DISTNAME=	gconfmm-2.0.1
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to GConf2

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	gconf/gconfmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gconf/gconfmm-2.0-uninstalled.pc.in

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
