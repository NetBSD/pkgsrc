# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		http://www.kerneled.com/projects/elf/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/src
BUILD_TARGET=	elf

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/elf.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
