# $NetBSD: Makefile,v 1.23 2001/02/13 11:47:03 tron Exp $
#

DISTNAME=		gnome-pim-1.2.0
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-pim/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=		bison:../../devel/bison
DEPENDS+=		gnome-core-*:../../x11/gnome-core

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LOCALEDIR=${LOCALEDIR}

PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

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
