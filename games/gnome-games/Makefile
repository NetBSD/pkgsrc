# $NetBSD: Makefile,v 1.2 2000/01/02 18:02:40 tron Exp $

DISTNAME=	gnome-games-1.0.51
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	xbill-*:../../games/xbill

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes

INSTALL_FILE=	${WRKDIR}/INSTALL

post-build:
	${SED} -e 's#@@INSTALL@@#${INSTALL}#' \
	  ${PKGDIR}/INSTALL >${INSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
