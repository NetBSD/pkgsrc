# $NetBSD: Makefile,v 1.2 1999/01/23 15:15:55 tron Exp $

DISTNAME=	WMMail.app-0.62
PKGNAME=	wmmail-0.62
CATEGORIES=	mail
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.utoronto.ca/~chanb/wmmail.html

BUILD_DEPENDS+=	automake:../../devel/automake
DEPENDS+=	windowmaker-0.50.2:../../x11/windowmaker

CONFLICTS=	wmmail-*

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
		${SED} -e 's#@@X11BASE@@#${X11BASE}#g' \
		       -e 's#@@LOCALBASE@@#${LOCALBASE}#g' \
		       <${WRKSRC}/WMMail.defaults \
		       >${PREFIX}/share/WindowMaker/Defaults/WWMail

.include "../../mk/bsd.pkg.mk"
