# $NetBSD: Makefile,v 1.5 2001/08/22 17:38:57 jlam Exp $

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
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
