# $NetBSD: Makefile,v 1.1.1.1 1999/05/25 15:30:34 bouyer Exp $
#

DISTNAME=       xmailbox-2.5
CATEGORIES=	mail x11
MASTER_SITES=   ftp://ftp.x.org/contrib/applications/

MAINTAINER=	bouyer@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	YES
MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'

post-install:
	${INSTALL} -d -m 555 -o ${BINOWN} -g ${BINGRP} ${PREFIX}/share/xmailbox
	cd ${WRKSRC}/icons && ${INSTALL_DATA} \
	     0xmail1.xpm 1xmail1.xpm 2xmail1.xpm 3xmail1.xpm 4xmail1.xpm \
	     5xmail1.xpm xmail1.xpm xnomail1.xpm \
	     ${PREFIX}/share/xmailbox

.include "../../mk/bsd.pkg.mk"
