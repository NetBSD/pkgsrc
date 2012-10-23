# $NetBSD: Makefile,v 1.9 2012/10/23 17:18:15 asau Exp $

DISTNAME=	corkscrew-2.0
CATEGORIES=	net
MASTER_SITES=	http://www.agroman.net/corkscrew/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.agroman.net/corkscrew/
COMMENT=	Tool for tunneling SSH through HTTP proxies
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	share/doc/corkscrew

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/corkscrew

.include "../../mk/bsd.pkg.mk"
