# $NetBSD: Makefile,v 1.13 2017/08/06 19:55:11 adam Exp $

DISTNAME=	rope-0.10.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://github.com/python-rope/rope
COMMENT=	Rope is a python refactoring library
LICENSE=	gnu-gpl-v2

#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
