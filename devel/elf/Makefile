# $NetBSD: Makefile,v 1.8 2004/12/03 15:14:54 wiz Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.kerneled.com/projects/elf/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/src
BUILD_TARGET=	elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/elf.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
