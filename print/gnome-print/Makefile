# $NetBSD: Makefile,v 1.36 2001/02/17 17:51:43 wiz Exp $
#

DISTNAME=		gnome-print-0.25
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

DEPENDS+=		gnome-libs>=1.0.56:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.5:../../textproc/libxml
DEPENDS+=		libunicode>=0.4:../../textproc/libunicode
DEPENDS+=		ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GHOSTSCRIPT=${LOCALBASE}/bin/gs
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
