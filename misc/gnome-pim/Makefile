# $NetBSD: Makefile,v 1.27 2001/04/07 19:23:54 rh Exp $
#

DISTNAME=		gnome-pim-1.4.0
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-pim/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Personal Information Manager for GNOME

BUILD_DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEDIR}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEDIR=		lib
.else
LOCALEDIR=		share
.endif

.include "../../mk/bsd.pkg.mk"
