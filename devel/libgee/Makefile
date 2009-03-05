# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 21:59:43 ahoka Exp $
#

DISTNAME=	libgee-0.1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/0.1/}
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libgee
COMMENT=	Library providing GObject-based interfaces and classes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gee-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
