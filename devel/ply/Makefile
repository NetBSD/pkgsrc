# $NetBSD: Makefile,v 1.18 2014/05/17 16:10:43 wiz Exp $

DISTNAME=	ply-3.4
PKGREVISION=	1
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
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/example && pax -rwppm * ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
