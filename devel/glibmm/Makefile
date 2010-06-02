# $NetBSD: Makefile,v 1.39 2010/06/02 16:43:26 adam Exp $

DISTNAME=	glibmm-2.24.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ bindings for glib
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:run
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar # added for pkg/42258

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
