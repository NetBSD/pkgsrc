# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:54 jschauma Exp $
#

DISTNAME=	nbtscan-1.5
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.org/software/

MAINTAINER=	tech-pkg@netbsd.org
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
