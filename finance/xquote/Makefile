# $NetBSD: Makefile,v 1.2 2000/12/15 02:18:08 wiz Exp $

DISTNAME=		xquote-2.2
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xquote.html

USE_IMAKE=		YES
USE_MOTIF=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../mk/bsd.pkg.mk"
