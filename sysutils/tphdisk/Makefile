# $NetBSD: Makefile,v 1.6 2023/12/23 09:27:16 zafer Exp $

DISTNAME=		tphdisk
PKGNAME=		tphdisk-20050112
CATEGORIES=		sysutils
MASTER_SITES=		https://www.samba.org/ftp/unpacked/junkcode/
EXTRACT_SUFX=		.c

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.samba.org/ftp/unpacked/junkcode/
COMMENT=		Create hibernation partitions for Thinkpads

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && cc -o tphdisk  tphdisk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tphdisk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
