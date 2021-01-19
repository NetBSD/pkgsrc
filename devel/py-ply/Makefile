# $NetBSD: Makefile,v 1.2 2021/01/19 21:05:22 adam Exp $

DISTNAME=	ply-3.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ply/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dabeaz.com/ply/
COMMENT=	Lex an yacc parsing tools for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && \
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} testlex.py
	cd ${WRKSRC}/test && \
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} testyacc.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
