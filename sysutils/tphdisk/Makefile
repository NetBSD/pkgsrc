# $NetBSD: Makefile,v 1.2 2010/01/27 20:28:15 joerg Exp $

DISTNAME=		tphdisk
PKGNAME=		tphdisk-20050112
CATEGORIES=		sysutils
MASTER_SITES=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
EXTRACT_SUFX=		.c

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://samba.anu.edu.au/ftp/unpacked/junkcode/
COMMENT=		Create hibernation partitions for Thinkpads

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && cc -o tphdisk  tphdisk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tphdisk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
