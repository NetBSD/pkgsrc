# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:41 jlam Exp $

DISTNAME=	fixelfprot-20040714
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mail-index.netbsd.org/tech-kern/2004/07/11/0002.html
COMMENT=	C program to fix ELF protection on .got table for PowerPC

ONLY_FOR_PLATFORM=	NetBSD-*-powerpc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes	# sources are part of pkgsrc entry
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${FILESDIR}/fixelfprot.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} fixelfprot.c -o fixelfprot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fixelfprot ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
