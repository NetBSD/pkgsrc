# $NetBSD: Makefile,v 1.4 2015/06/07 12:33:50 gdt Exp $

DISTNAME=		tphdisk
PKGNAME=		tphdisk-20050112
CATEGORIES=		sysutils
MASTER_SITES=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
EXTRACT_SUFX=		.c

MAINTAINER=		pkgsrc-users@netbsd.org
HOMEPAGE=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
COMMENT=		Create hibernation partitions for Thinkpads

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && cc -o tphdisk  tphdisk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tphdisk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
