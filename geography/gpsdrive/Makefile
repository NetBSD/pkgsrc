# $NetBSD: Makefile,v 1.6 2005/12/13 15:29:48 ghen Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	8
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

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash=	src/gpsfetchmap
SUBST_SED.bash=		-e 's,\#!/bin/bash,\#!/bin/sh,'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
