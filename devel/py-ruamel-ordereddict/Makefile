# $NetBSD: Makefile,v 1.4 2017/10/28 08:49:30 adam Exp $

DISTNAME=	ruamel.ordereddict-0.4.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.ordereddict/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://bitbucket.org/ruamel/ordereddict
COMMENT=	Version of dict that keeps keys in insertion resp. sorted order
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} testordereddict.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
