# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:46 agc Exp $

DISTNAME=		abuse_pd
PKGNAME=		abuse-2.0
CATEGORIES=		games x11
MASTER_SITES=		http://www.crack.com/games/abuse/
DISTFILES=		${DISTNAME}.tgz abuse_data.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.crack.com/games/abuse/index.html

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${X11BASE}/lib"
USE_GMAKE=		yes

post-extract:
	${EXTRACT_CMD} -xzmf ${DISTDIR}/abuse_data.tar.gz -C ${WRKSRC}/abuse

.include "../../mk/bsd.pkg.mk"
