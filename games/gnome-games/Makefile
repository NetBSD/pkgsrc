# $NetBSD: Makefile,v 1.14 2000/11/24 11:12:29 abs Exp $

DISTNAME=		gnome-games-1.2.0
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-games/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
DEPENDS+=		gnome-core-*:../../x11/gnome-core
# Required for ports which don't build "libgtop".
DEPENDS+=		guile-[0-9]*:../../lang/guile
DEPENDS+=		xbill-*:../../games/xbill

USE_GMAKE=		# defined
USE_X11BASE=		# defined
USE_CURSES=		# defined
USE_LIBTOOL=		# defined
USE_LIBINTL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}
CONFIGURE_ARGS+=	--localstatedir=/var

PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

INSTALL_FILE=		${WRKDIR}/INSTALL

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

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

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}
.endif

.include "../../mk/bsd.pkg.mk"
