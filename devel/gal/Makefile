# $NetBSD: Makefile,v 1.12 2001/05/22 16:07:24 rh Exp $
#

DISTNAME=	gal-0.8
CATEGORIES=	gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gal/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Application Libraries

DEPENDS+=	libiconv-*:../../converters/libiconv
DEPENDS+=	gnome-libs>=1.2.13:../../x11/gnome-libs
DEPENDS+=	gnome-print>=0.28:../../print/gnome-print
DEPENDS+=	gnome-vfs>=1.0:../../sysutils/gnome-vfs
DEPENDS+=	libglade>=0.16:../../devel/libglade
DEPENDS+=	libunicode>=0.4:../../textproc/libunicode
DEPENDS+=	bonobo>=1.0.4:../../devel/bonobo

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_LIBINTL=	YES

CONFIGURE_ARGS+=	-with-libiconv=${LOCALBASE}

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
