# $NetBSD: Makefile,v 1.2 2000/12/15 01:42:13 wiz Exp $

DISTNAME=		xinvest-2.6
CATEGORIES=		finance x11
MASTER_SITES=		http://sunsite.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.dk/xinvest/xinvest.html

USE_IMAKE=		YES
USE_MOTIF=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES

post-patch:
	${TOUCH} ${WRKSRC}/Xinvest.man

.include "../../mk/bsd.pkg.mk"
