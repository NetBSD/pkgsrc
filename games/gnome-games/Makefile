# $NetBSD: Makefile,v 1.9 2000/06/27 08:30:47 tron Exp $

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
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
GOOD_CURSES=	1.4[Y-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OS_VERSION:M${PATTERN}} != ""
CURSES_GOOD?=	# defined
.endif
.endfor

.if !defined(CURSES_GOOD)
DEPENDS+=	ncurses>=5.0:../../devel/ncurses
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}
.endif
.endif

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
