# $NetBSD: Makefile,v 1.1 2015/12/02 18:22:10 drochner Exp $
#

PYMODULENAME=		ply
PYMODULEVER=		3.8
DISTNAME=		${PYMODULENAME}-${PYMODULEVER}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.dabeaz.com/ply/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://www.dabeaz.com/ply/
COMMENT=		Lex an yacc parsing tools for Python
LICENSE=		gnu-lgpl-v2.1

do-test:
	cd ${WRKSRC}/test; \
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} testlex.py; \
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} testyacc.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
