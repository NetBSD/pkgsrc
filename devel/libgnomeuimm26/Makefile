# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:30 tv Exp $
#

DISTNAME=		libgnomeuimm-2.6.0
PKGNAME=		libgnomeuimm26-2.6.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomeuimm/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for libgnomeui

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomeui/libgnomeuimm-2.6.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgnomemm26/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm26/buildlink3.mk"
.include "../../devel/gconfmm26/buildlink3.mk"
.include "../../devel/libglademm24/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
