# $NetBSD: Makefile,v 1.10 2001/03/19 12:57:43 tron Exp $
#

DISTNAME=	gal-0.5
CATEGORIES=	gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gal/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Application Libraries

DEPENDS+=	libiconv-*:../../converters/libiconv
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.25:../../print/gnome-print
DEPENDS+=	gnome-vfs-*:../../sysutils/gnome-vfs
DEPENDS+=	libglade>=0.13:../../devel/libglade
DEPENDS+=	libunicode>=0.4:../../textproc/libunicode
DEPENDS+=	bonobo>=0.26:../../devel/bonobo

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_LIBINTL=	YES

CONFIGURE_ARGS+=	-with-libiconv=${LOCALBASE}

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
