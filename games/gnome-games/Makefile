# $NetBSD: Makefile,v 1.11 2000/11/02 03:25:33 wiz Exp $

DISTNAME=		gnome-games-1.2.0
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-games/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-core-*:../../x11/gnome-core
# Required for ports which don't build "libgtop".
DEPENDS+=		guile-[0-9]*:../../lang/guile
DEPENDS+=		xbill-*:../../games/xbill

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--localstatedir=/var

USE_X11BASE=		# defined
USE_CURSES=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INSTALL_FILE=		${WRKDIR}/INSTALL

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}
.endif

.include "../../mk/bsd.pkg.mk"
