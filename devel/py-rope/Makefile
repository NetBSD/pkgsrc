# $NetBSD: Makefile,v 1.11 2016/08/27 01:51:56 maya Exp $

VERS=		0.10.2
DISTNAME=	rope-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://github.com/python-rope/rope
COMMENT=	Rope is a python refactoring library
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
