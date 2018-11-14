# $NetBSD: Makefile,v 1.70 2018/11/14 22:21:17 kleink Exp $

DISTNAME=	libgnomeuimm-2.28.0
PKGREVISION=	41
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeuimm/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
#HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnomeui

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomeui/libgnomeuimm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libgnomemm/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
