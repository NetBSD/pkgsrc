# $NetBSD: Makefile,v 1.45 2002/03/26 09:20:44 rh Exp $
#

DISTNAME=		gnome-print-0.35
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-print/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Prototype implementation of the Gnome Printing Architecture

DEPENDS+=		ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		GHOSTSCRIPT=${LOCALBASE}/bin/gs
# override HOME to avoid trying to install ${HOME}/.gnome
MAKE_ENV+=		HOME=${WRKSRC}

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../textproc/libunicode/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
