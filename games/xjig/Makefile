# $NetBSD: Makefile,v 1.1 1998/04/23 09:03:43 hubertf Exp $
#

DISTNAME=       xjig-2.4
CATEGORIES=	games x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

USE_IMAKE=      yes
USE_X11=      yes
ALL_TARGET=	xjig xjig.0

post-install:
	${INSTALL_DATA_DIR} ${X11BASE}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11BASE}/lib/xjig

.include "../../mk/bsd.pkg.mk"
