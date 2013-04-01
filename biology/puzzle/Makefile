# $NetBSD: Makefile,v 1.14 2013/04/01 08:56:43 sbd Exp $

DISTNAME=	tree-puzzle-5.2
PKGNAME=	${DISTNAME:S/^tree-//}
CATEGORIES=	biology
MASTER_SITES=	http://www.tree-puzzle.de/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://www.tree-puzzle.de/
COMMENT=	Maximum likelihood analysis of molecular sequence data
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE= no

INSTALLATION_DIRS=	share/doc/puzzle \
			share/examples/puzzle

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} tree-puzzle.pdf	\
		${DESTDIR}${PREFIX}/share/doc/puzzle
	cd ${WRKSRC}/data && ${INSTALL_DATA} EF.* *.a *.n *.b	\
		${DESTDIR}${PREFIX}/share/examples/puzzle

SUBST_CLASSES+=		testeq
SUBST_STAGE.testeq=	post-extract
SUBST_MESSAGE.testeq=	Replace non-portable "==" operator for test(1)
SUBST_FILES.testeq=	tests/*test
SUBST_SED.testeq=	-e 's/==/=/g'

TEST_TARGET=		check

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
