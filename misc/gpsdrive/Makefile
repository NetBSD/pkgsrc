# $NetBSD: Makefile,v 1.10 2004/07/22 11:36:00 agc Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

DEPENDS+=	gpsd>=1.07:../../misc/gpsd

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

USE_LANGUAGE=	c c++

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
