# $NetBSD: Makefile,v 1.6 2000/08/23 23:14:25 tron Exp $
#

DISTNAME=		xbill-2.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/

USE_IMAKE=		YES
USE_XPM=		YES
NO_INSTALL_MANPAGES=	YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6

.include "../../mk/bsd.pkg.mk"
