# $NetBSD: Makefile,v 1.5 2001/08/22 17:38:57 jlam Exp $

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
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
