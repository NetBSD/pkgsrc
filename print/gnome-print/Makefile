# $NetBSD: Makefile,v 1.61 2004/03/16 08:39:29 tron Exp $

DISTNAME=		gnome-print-0.36
PKGREVISION=		5
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-print/0.36/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-admin		# currently unstable

# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

.include "../../databases/db4/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
