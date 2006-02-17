# $NetBSD: Makefile,v 1.2 2006/02/17 07:48:02 martti Exp $

DISTNAME=	corkscrew-2.0
CATEGORIES=	net
MASTER_SITES=	http://www.agroman.net/corkscrew/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.agroman.net/corkscrew
COMMENT=	Tool for tunneling SSH through HTTP proxies

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/corkscrew
	${INSTALL_DATA} ${WRKSRC:Q}/README ${PREFIX:Q}/share/doc/corkscrew

.include "../../mk/bsd.pkg.mk"
