# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:13 wiz Exp $
#

DISTNAME=	fix4SA110rev2-1.0
NO_WRKSUBDIR=	yes
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/arch/arm32/misc/
DISTFILES=	fix4SA110rev2.c fix4SA110rev2.README

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/arch/arm32/misc/fix4SA110rev2.README
COMMENT=	Modify arm32 binaries to work around SA rev2 problems

ONLY_FOR_PLATFORM= NetBSD-*-arm32
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/fix4SA110rev2 ${WRKSRC}/fix4SA110rev2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fix4SA110rev2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fix4SA110rev2.README ${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
