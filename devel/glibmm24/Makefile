# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:27 tv Exp $
#

DISTNAME=		glibmm-2.4.3
PKGNAME=		glibmm24-2.4.3
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glibmm/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for glib

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib/glibmm-2.4.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
