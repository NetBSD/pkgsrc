# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 20:44:05 drochner Exp $
#

DISTNAME=		libgnomeuimm-2.0.0
PKGNAME=		libgnomeuimm20-2.0.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomeuimm/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for libgnomeui

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomeui/libgnomeuimm-2.0.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgnomemm20/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm20/buildlink3.mk"
# gconfmm must be 2.0
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
