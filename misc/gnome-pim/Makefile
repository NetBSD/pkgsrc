# $NetBSD: Makefile,v 1.32 2002/10/19 10:54:55 rh Exp $
#

DISTNAME=		gnome-pim-1.4.0
PKGREVISION=		1
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pim/1.4/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Personal Information Manager for GNOME

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		gnome-core>=1.4.0.4nb1:../../x11/gnome-core

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-I${LOCALBASE}/include
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
