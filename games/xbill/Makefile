# $NetBSD: Makefile,v 1.5 1999/12/29 17:15:17 pooka Exp $
#

DISTNAME=		xbill-2.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6

.include "../../mk/bsd.pkg.mk"
