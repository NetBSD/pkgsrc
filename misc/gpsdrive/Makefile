# $NetBSD: Makefile,v 1.8 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

DEPENDS+=	gpsd>=1.07:../../misc/gpsd

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
