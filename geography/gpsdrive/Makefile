# $NetBSD: Makefile,v 1.10 2006/04/17 13:46:30 wiz Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	10
CATEGORIES=	geography
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

DEPENDS+=	gpsd>=1.07:../../geography/gpsd
DEPENDS+=	wget>=1:../../net/wget

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

USE_LANGUAGE=	c c++

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	src/gpsfetchmap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
