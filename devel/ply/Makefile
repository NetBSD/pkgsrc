# $NetBSD: Makefile,v 1.15 2012/10/31 11:19:25 asau Exp $

DISTNAME=	ply-3.3
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/

MAINTAINER=	nonaka@netbsd.org
HOMEPAGE=	http://www.dabeaz.com/ply/
COMMENT=	Python Lex-Yacc

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/ply
EGDIR=	${PREFIX}/share/examples/ply
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

do-test:
.for filtst in testlex.py testyacc.py
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/$${filtst}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/example && pax -rwppm * ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
