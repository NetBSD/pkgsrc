# $NetBSD: Makefile,v 1.11 2004/02/14 17:21:37 jlam Exp $
#

DISTNAME=	gconfmm-2.0.1
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to GConf2

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make

PKGCONFIG_OVERRIDE=	${WRKSRC}/gconf/gconfmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gconf/gconfmm-2.0-uninstalled.pc.in

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
