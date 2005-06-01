# $NetBSD: Makefile,v 1.16 2005/06/01 18:02:49 jlam Exp $

DISTNAME=		abuse_pd
PKGNAME=		abuse-2.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.crack.com/games/abuse/
DISTFILES=		${DISTNAME}.tgz abuse_data.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.crack.com/games/abuse/index.html
COMMENT=		Full color 320x200 arcade quality platform shooter

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="${X11_LDFLAGS}"
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c c++
PKGSRC_USE_TOOLS+=	gtar

NOT_FOR_PLATFORM=	NetBSD-*-arm32

.include "../../mk/x11.buildlink3.mk"

post-extract:
	cd ${WRKSRC}/abuse && \
	    ${GZCAT} ${DISTDIR}/abuse_data.tar.gz | ${GTAR} xf -

.include "../../mk/bsd.pkg.mk"
