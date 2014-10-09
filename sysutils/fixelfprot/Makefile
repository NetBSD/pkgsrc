# $NetBSD: Makefile,v 1.11 2014/10/09 14:06:57 wiz Exp $

DISTNAME=	fixelfprot-20040714
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mail-index.NetBSD.org/tech-kern/2004/07/11/0002.html
COMMENT=	C program to fix ELF protection on .got table for PowerPC

ONLY_FOR_PLATFORM=	NetBSD-*-powerpc

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-extract:
	${CP} ${FILESDIR}/fixelfprot.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fixelfprot.c -o fixelfprot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fixelfprot ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
