# $NetBSD: Makefile,v 1.1.1.1 2006/08/21 13:19:33 gdt Exp $

DISTNAME=		tphdisk
PKGNAME=		tphdisk-20050112
CATEGORIES=		sysutils
MASTER_SITES=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
EXTRACT_SUFX=		.c

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
COMMENT=		Create hibernation partitions for Thinkpads

WRKSRC=			${WRKDIR}

do-build:
	cd ${WRKSRC} && cc -o tphdisk  tphdisk.c

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} tphdisk ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
