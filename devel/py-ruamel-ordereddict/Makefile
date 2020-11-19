# $NetBSD: Makefile,v 1.6 2020/11/19 10:21:38 adam Exp $

DISTNAME=	ruamel.ordereddict-0.4.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.ordereddict/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://sourceforge.net/projects/ruamel-ordereddict/
COMMENT=	Version of dict that keeps keys in insertion resp. sorted order
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} testordereddict.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
