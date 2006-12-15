# $NetBSD: Makefile,v 1.14 2006/12/15 20:32:58 joerg Exp $
#

DISTNAME=       xmailbox-2.5
PKGREVISION=	2
CATEGORIES=	mail x11
MASTER_SITES=   ${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Enhanced xbiff, with pixmap and sound support

USE_IMAKE=	YES

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmailbox
	cd ${WRKSRC}/icons && ${INSTALL_DATA} \
	     0xmail1.xpm 1xmail1.xpm 2xmail1.xpm 3xmail1.xpm 4xmail1.xpm \
	     5xmail1.xpm xmail1.xpm xnomail1.xpm \
	     ${PREFIX}/share/xmailbox

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
