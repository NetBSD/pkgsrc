# $NetBSD: Makefile,v 1.3 1999/04/15 20:39:45 tron Exp $

DISTNAME=		xinvest-2.5.1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.sunsite.auc.dk/xinvest/xinvest.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		yes
USE_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${TOUCH} ${WRKSRC}/Xinvest.man

.include "../../mk/bsd.pkg.mk"
