# $NetBSD: Makefile,v 1.7 2002/12/24 06:10:22 wiz Exp $
#

DISTNAME=		libgnomeprint-1.116.0
PKGREVISION=		3
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomeprint/1.116/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Library for the GNOME2 Printing Architecture

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES
USE_X11=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	${MV} ${WRKSRC}/installer/README.installer ${WRKSRC}/installer/README.installer.2

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
