## $NetBSD: Makefile,v 1.24 2000/11/17 20:15:26 tron Exp $

DISTNAME=		gnome-utils-1.2.0
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-utils/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
BUILD_DEPENDS+=		bison:../../devel/bison
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
DEPENDS+=		gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.9:../../devel/libgtop
DEPENDS+=		libglade>=0.13:../../devel/libglade

USE_GMAKE=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include \
			LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

.include "../../mk/bsd.pkg.mk"
