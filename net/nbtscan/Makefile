# $NetBSD: Makefile,v 1.3 2003/03/16 14:22:06 cjep Exp $
# FreeBSD Id: ports/net/nbtscan/Makefile,v 1.2 2001/08/25 10:53:28 kris Exp

DISTNAME=	nbtscan-1.0.3
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.org/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.inetcat.org/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

ALL_TARGET=	nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nbtscan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
