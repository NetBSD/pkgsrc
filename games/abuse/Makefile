# $NetBSD: Makefile,v 1.8 2001/02/16 15:10:41 wiz Exp $

DISTNAME=		abuse_pd
PKGNAME=		abuse-2.0
CATEGORIES=		games x11
MASTER_SITES=		http://www.crack.com/games/abuse/
DISTFILES=		${DISTNAME}.tgz abuse_data.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.crack.com/games/abuse/index.html
COMMENT=		Full color 320x200 arcade quality platform shooter

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${X11BASE}/lib"
USE_GMAKE=		yes

NOT_FOR_PLATFORM=	NetBSD-*-arm32

post-extract:
	cd ${WRKSRC}/abuse && \
	    ${GZCAT} ${DISTDIR}/abuse_data.tar.gz | ${GTAR} xf -

.include "../../mk/bsd.pkg.mk"
