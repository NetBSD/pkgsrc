# $NetBSD: Makefile,v 1.21 2009/01/12 15:58:46 wiz Exp $

DISTNAME=	libgnomeuimm-2.24.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeuimm/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for libgnomeui

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgnomeui/libgnomeuimm-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libgnomemm/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
