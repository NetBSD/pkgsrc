# $NetBSD: Makefile,v 1.48 2002/08/26 19:39:29 mjl Exp $
#

DISTNAME=		gnome-print-0.36
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

DEPENDS+=		ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

BUILDLINK_DEPENDS.libxml=	libxml>=1.8.8
BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.7.0

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-admin		# currently unstable

# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../textproc/libunicode/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
