# $NetBSD: Makefile,v 1.12 1999/06/21 04:53:14 jlam Exp $

DISTNAME=	WMMail.app-0.62
PKGNAME=	wmmail-0.62
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.utoronto.ca/~chanb/wmmail.html

BUILD_DEPENDS+=	automake:../../devel/automake
DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker

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
		       >${PREFIX}/etc/WindowMaker/WMMail

.include "../../mk/bsd.pkg.mk"
