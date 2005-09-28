# $NetBSD: Makefile,v 1.4 2005/09/28 20:52:27 rillig Exp $

DISTNAME= 	mtscan-20050129
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mail-index.netbsd.org/port-i386/2005/01/29/0011.html
COMMENT=	Magtape scanner - reports record and file-mark structure

NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} -O2 -DMTIO -o mtscan mtscan.c -ltermcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtscan ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
