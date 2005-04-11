# $NetBSD: Makefile,v 1.11 2005/04/11 21:46:28 tv Exp $
#

DISTNAME=       xmailbox-2.5
PKGREVISION=	1
CATEGORIES=	mail x11
MASTER_SITES=   ${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Enhanced xbiff, with pixmap and sound support

USE_IMAKE=	YES

MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmailbox
	cd ${WRKSRC}/icons && ${INSTALL_DATA} \
	     0xmail1.xpm 1xmail1.xpm 2xmail1.xpm 3xmail1.xpm 4xmail1.xpm \
	     5xmail1.xpm xmail1.xpm xnomail1.xpm \
	     ${PREFIX}/share/xmailbox

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
