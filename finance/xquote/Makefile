# $NetBSD: Makefile,v 1.1.1.1 2000/12/11 13:53:25 wiz Exp $

DISTNAME=		xquote-2.1
CATEGORIES=		finance x11
MASTER_SITES=		http://www.sunsite.auc.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.auc.dk/xinvest/xquote.html

USE_IMAKE=		YES
USE_MOTIF=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../mk/bsd.pkg.mk"
