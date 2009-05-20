# $NetBSD: Makefile,v 1.14 2009/05/20 00:58:12 wiz Exp $
#

DISTNAME=	elf-0.5.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		http://www.kerneled.com/projects/elf/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.kerneled.com/projects/elf/
COMMENT=	ELF header analyzer

PKG_DESTDIR_SUPPORT=	user-destdir

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
