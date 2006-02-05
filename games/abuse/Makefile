# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:12 joerg Exp $

DISTNAME=		abuse_pd
PKGNAME=		abuse-2.0
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.crack.com/games/abuse/
DISTFILES=		${DISTNAME}.tgz abuse_data.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.crack.com/games/abuse/index.html
COMMENT=		Full color 320x200 arcade quality platform shooter

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS=${X11_LDFLAGS:Q}
USE_TOOLS+=		gmake gtar
USE_LANGUAGES+=		c c++

NOT_FOR_PLATFORM=	NetBSD-*-arm32

.include "../../mk/x11.buildlink3.mk"

post-extract:
	cd ${WRKSRC}/abuse && \
	    ${GZCAT} ${DISTDIR}/abuse_data.tar.gz | ${GTAR} xf -

.include "../../mk/bsd.pkg.mk"
