# $NetBSD: Makefile,v 1.7 2004/02/14 00:54:45 grant Exp $
#

DISTNAME=	nbtscan-1.5
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.org/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.inetcat.org/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes

ALL_TARGET=	nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nbtscan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
