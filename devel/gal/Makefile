# $NetBSD: Makefile,v 1.6 2000/12/31 09:35:24 rh Exp $
#

DISTNAME=	gal-0.4.1
CATEGORIES=	gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gal/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.25:../../print/gnome-print
DEPENDS+=	gnome-vfs-*:../../sysutils/gnome-vfs
DEPENDS+=	libglade>=0.14:../../devel/libglade
DEPENDS+=	libunicode>=0.4:../../textproc/libunicode
DEPENDS+=	bonobo>=0.26:../../devel/bonobo

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
