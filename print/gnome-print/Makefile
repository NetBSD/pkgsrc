# $NetBSD: Makefile,v 1.64 2004/10/03 00:18:05 tv Exp $

DISTNAME=		gnome-print-0.36
PKGREVISION=		5
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-print/0.36/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-admin		# currently unstable

# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
