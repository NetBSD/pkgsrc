# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:29 tv Exp $
#

DISTNAME=		libglademm-2.4.1
PKGNAME=		libglademm24-2.4.1
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglademm/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ bindings for libglade

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libglade/libglademm-2.4.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
