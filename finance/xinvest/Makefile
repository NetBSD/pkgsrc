# $NetBSD: Makefile,v 1.6 2001/09/08 19:55:45 jlam Exp $

DISTNAME=		xinvest-2.6
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xinvest.html
COMMENT=		Personal finance tracking and performance tool

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xinvest.man

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
