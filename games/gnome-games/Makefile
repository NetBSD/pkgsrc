# $NetBSD: Makefile,v 1.19 2001/02/06 03:16:57 fredb Exp $

DISTNAME=		gnome-games-1.2.0
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-games/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=		gettextize:../../devel/gettext
DEPENDS+=		gnome-core-*:../../x11/gnome-core
# Required for ports which don't build "libgtop".
DEPENDS+=		guile-[0-9]*:../../lang/guile

CONFLICTS=		xbill-*

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_CURSES=		YES
USE_LIBTOOL=		YES
USE_LIBINTL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}
CONFIGURE_ARGS+=	--localstatedir=/var
CFLAGS+=		-I${LOCALBASE}/include

INSTALL_FILE=		${WRKDIR}/INSTALL
PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

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
