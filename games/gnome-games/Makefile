# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:25 rh Exp $

DISTNAME=	gnome-games-1.0.51
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-games/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
# Required for ports which don't build "libgtop".
DEPENDS+=	guile-[0-9]*:../../lang/guile
DEPENDS+=	xbill-*:../../games/xbill

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_PKGLIBTOOL=	yes

INSTALL_FILE=	${WRKDIR}/INSTALL

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
