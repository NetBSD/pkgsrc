# $NetBSD: Makefile,v 1.4 2000/11/25 14:11:11 rh Exp $
#

DISTNAME=	gal-0.2.2
CATEGORIES=	gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gal/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.25:../../print/gnome-print
DEPENDS+=	gnome-vfs-*:../../sysutils/gnome-vfs
DEPENDS+=	libglade>=0.14:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
