# $NetBSD: Makefile,v 1.3 2003/01/08 17:29:06 tsarna Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

DEPENDS+=	gpsd>=1.07:../../misc/gpsd

GNU_CONFIGURE=	YES
USE_BUILDLINK2= YES

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
