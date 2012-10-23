# $NetBSD: Makefile,v 1.3 2012/10/23 19:51:27 asau Exp $

DISTNAME=		tphdisk
PKGNAME=		tphdisk-20050112
CATEGORIES=		sysutils
MASTER_SITES=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
EXTRACT_SUFX=		.c

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
COMMENT=		Create hibernation partitions for Thinkpads

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && cc -o tphdisk  tphdisk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tphdisk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
