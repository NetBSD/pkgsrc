# $NetBSD: Makefile,v 1.1 1998/08/15 14:19:52 frueauf Exp $
#

DISTNAME=		xbill-2.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6

.include "../../mk/bsd.pkg.mk"
