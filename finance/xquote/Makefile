# $NetBSD: Makefile,v 1.7 2002/10/08 12:35:15 jlam Exp $

DISTNAME=		xquote-2.2
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xquote.html
COMMENT=		WWW ticker symbol quote retrieval program

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
