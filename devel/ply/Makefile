# $NetBSD: Makefile,v 1.24 2023/08/14 05:24:14 wiz Exp $

DISTNAME=	ply-3.9
PKGREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/

MAINTAINER=	nonaka@NetBSD.org
HOMEPAGE=	http://www.dabeaz.com/ply/
COMMENT=	Python Lex-Yacc
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DOCDIR=	${PREFIX}/share/doc/ply
EGDIR=	${PREFIX}/share/examples/ply
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

do-test:
.for filtst in testlex.py testyacc.py
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/$${filtst}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/example && pax -rwppm * ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
