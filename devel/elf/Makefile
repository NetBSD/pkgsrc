# $NetBSD: Makefile,v 1.5 2004/04/25 05:23:54 snj Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kerneled.com/projects/elf/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/src
ALL_TARGET=	elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/elf.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
