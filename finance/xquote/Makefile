# $NetBSD: Makefile,v 1.6 2001/09/08 19:55:45 jlam Exp $

DISTNAME=		xquote-2.2
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xquote.html
COMMENT=		WWW ticker symbol quote retrieval program

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
