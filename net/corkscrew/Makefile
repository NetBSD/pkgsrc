# $NetBSD: Makefile,v 1.7 2009/05/12 12:27:20 martti Exp $

DISTNAME=	corkscrew-2.0
CATEGORIES=	net
MASTER_SITES=	http://www.agroman.net/corkscrew/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.agroman.net/corkscrew/
COMMENT=	Tool for tunneling SSH through HTTP proxies
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	share/doc/corkscrew
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/corkscrew

.include "../../mk/bsd.pkg.mk"
