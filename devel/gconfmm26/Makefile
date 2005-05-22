# $NetBSD: Makefile,v 1.4 2005/05/22 20:07:51 jlam Exp $
#

DISTNAME=		gconfmm-2.6.1
PKGNAME=		gconfmm26-2.6.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gconfmm/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for gconf

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gconf/gconfmm-2.6.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
