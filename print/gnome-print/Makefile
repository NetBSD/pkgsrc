# $NetBSD: Makefile,v 1.40 2001/10/01 07:04:03 rh Exp $
#

DISTNAME=		gnome-print-0.29
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

DEPENDS+=		libunicode>=0.4:../../textproc/libunicode
DEPENDS+=		ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GHOSTSCRIPT=${LOCALBASE}/bin/gs
# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
