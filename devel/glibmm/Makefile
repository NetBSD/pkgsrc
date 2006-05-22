# $NetBSD: Makefile,v 1.12 2006/05/22 11:03:59 adam Exp $

DISTNAME=	glibmm-2.10.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for glib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC:Q}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
