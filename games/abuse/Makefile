# $NetBSD: Makefile,v 1.4 1999/04/05 16:56:34 mycroft Exp $

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
	cd ${WRKSRC}/abuse && \
	    ${GUNZIP_CMD} ${DISTDIR}/abuse_data.tar.gz | /usr/bin/tar xf -

.include "../../mk/bsd.pkg.mk"
