# $NetBSD: Makefile,v 1.6 2006/02/08 18:50:52 drochner Exp $

DISTNAME=	glibmm-2.8.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ bindings for glib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
