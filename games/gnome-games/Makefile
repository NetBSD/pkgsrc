# $NetBSD: Makefile,v 1.12 2000/11/09 19:46:10 mycroft Exp $

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
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--localstatedir=/var

INSTALL_FILE=		${WRKDIR}/INSTALL

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	#cd ${WRKSRC} && ${MV} -f aclocal.m4 acinclude.m4
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}
.endif

.include "../../mk/bsd.pkg.mk"
