# $NetBSD: Makefile,v 1.8 2004/04/23 22:58:10 wiz Exp $

DISTNAME=		xquote-2.2
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xquote.html
COMMENT=		WWW ticker symbol quote retrieval program

USE_BUILDLINK3=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
