# $NetBSD: Makefile,v 1.12 2012/10/23 19:51:02 asau Exp $
#

DISTNAME=	fix4SA110rev2-1.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/arch/arm32/misc/
DISTFILES=	fix4SA110rev2.c fix4SA110rev2.README

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/arch/arm32/misc/fix4SA110rev2.README
COMMENT=	Modify arm32 binaries to work around SA rev2 problems

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/fix4SA110rev2 ${WRKSRC}/fix4SA110rev2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fix4SA110rev2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fix4SA110rev2.README ${DESTDIR}${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
