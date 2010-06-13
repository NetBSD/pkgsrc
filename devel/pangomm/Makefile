# $NetBSD: Makefile,v 1.9 2010/06/13 22:44:09 wiz Exp $

DISTNAME=	pangomm-2.26.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pangomm/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ bindings for pangomm

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gtkmm<=2.13.5

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:run
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pango/pangomm-1.4.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.pango+=	pango>=1.26.0

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
