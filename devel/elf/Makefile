# $NetBSD: Makefile,v 1.15 2012/10/31 11:16:55 asau Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		http://www.kerneled.com/projects/elf/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

GNU_CONFIGURE=	YES

BUILD_DIRS=	${WRKSRC}/src
BUILD_TARGET=	elf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elf ${DESTDIR:Q}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/elf.1 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
