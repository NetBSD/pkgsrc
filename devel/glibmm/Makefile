# $NetBSD: Makefile,v 1.1.1.1 2005/07/22 21:12:21 adam Exp $

DISTNAME=	glibmm-2.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for glib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
