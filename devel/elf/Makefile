# $NetBSD: Makefile,v 1.20 2017/01/19 18:52:05 agc Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP}
MASTER_SITES+=	http://www.kerneled.com/projects/elf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

GNU_CONFIGURE=	YES

BUILD_DIRS=	src
BUILD_TARGET=	elf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elf ${DESTDIR:Q}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/elf.1 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
