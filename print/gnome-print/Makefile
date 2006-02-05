# $NetBSD: Makefile,v 1.71 2006/02/05 23:10:37 joerg Exp $

DISTNAME=		gnome-print-0.37
PKGREVISION=		1
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-print/0.37/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gs:run

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-admin		# currently unstable

# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC:Q}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
