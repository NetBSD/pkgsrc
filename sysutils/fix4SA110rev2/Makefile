# $NetBSD: Makefile,v 1.11 2009/02/10 12:49:56 abs Exp $
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

PKG_DESTDIR_SUPPORT= 	user-destdir
INSTALLATION_DIRS=	bin share/doc

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/fix4SA110rev2 ${WRKSRC}/fix4SA110rev2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fix4SA110rev2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fix4SA110rev2.README ${DESTDIR}${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
