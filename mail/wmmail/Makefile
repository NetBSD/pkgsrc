# $NetBSD: Makefile,v 1.7 1999/02/22 01:53:15 tron Exp $

DISTNAME=	WMMail.app-0.62
PKGNAME=	wmmail-0.62
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.utoronto.ca/~chanb/wmmail.html

BUILD_DEPENDS+=	automake:../../devel/automake
DEPENDS+=	windowmaker-0.51.0:../../x11/windowmaker

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" SHELL="/bin/sh"

post-install:
		${SED} -e 's#@@X11BASE@@#${X11BASE}#g' \
		       -e 's#@@LOCALBASE@@#${LOCALBASE}#g' \
		       <${WRKSRC}/WMMail.defaults \
		       >${PREFIX}/share/WindowMaker/Defaults/WWMail

.include "../../mk/bsd.pkg.mk"
