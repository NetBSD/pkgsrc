# $NetBSD: Makefile,v 1.4 2020/03/20 11:58:26 nia Exp $
#

DISTNAME=	gutcheck
PKGNAME=	gutcheck-0.991
CATEGORIES=	textproc
MASTER_SITES=	http://pglaf.org/~jtinsley/gutcheck/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gutcheck.sourceforge.net/
COMMENT=	Text checker specialized in reporting problems spellcheckers overlook
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin share/doc/gutcheck

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o gutcheck gutcheck.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gutcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gutcheck.txt \
		${DESTDIR}${PREFIX}/share/doc/gutcheck

.include "../../mk/bsd.pkg.mk"
