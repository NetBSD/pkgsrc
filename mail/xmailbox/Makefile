# $NetBSD: Makefile,v 1.18 2010/02/04 14:42:33 joerg Exp $
#

DISTNAME=	xmailbox-2.5
PKGREVISION=	3
CATEGORIES=	mail x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Enhanced xbiff, with pixmap and sound support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

INSTALLATION_DIRS+=	share/xmailbox

post-install:
	cd ${WRKSRC}/icons && ${INSTALL_DATA} \
	     0xmail1.xpm 1xmail1.xpm 2xmail1.xpm 3xmail1.xpm 4xmail1.xpm \
	     5xmail1.xpm xmail1.xpm xnomail1.xpm \
	     ${DESTDIR}${PREFIX}/share/xmailbox

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
