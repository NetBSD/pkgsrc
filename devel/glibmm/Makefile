# $NetBSD: Makefile,v 1.28 2008/04/15 13:17:49 obache Exp $

DISTNAME=	glibmm-2.16.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ bindings for glib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:run
PKGCONFIG_OVERRIDE+=	${WRKSRC:Q}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
