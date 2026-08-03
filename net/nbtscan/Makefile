# $NetBSD: Makefile,v 1.18 2026/08/03 13:12:30 wiz Exp $

DISTNAME=	nbtscan-1.5.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.net/software/

PATCHFILES=		nbtscan-jumbo-patch-20141122.gz
PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/nbtscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.inetcat.net/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}a
BUILD_TARGET=	nbtscan

INSTALLATION_DIRS=	bin share/doc/nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
