# $NetBSD: Makefile,v 1.1.1.1 2002/12/26 19:55:01 tsarna Exp $

DISTNAME=	gpsdrive-1.31
CATEGORIES=	misc
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

GNU_CONFIGURE=	YES
USE_BUILDLINK2= YES

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
