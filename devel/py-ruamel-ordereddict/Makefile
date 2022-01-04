# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:37 wiz Exp $

DISTNAME=	ruamel.ordereddict-0.4.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
PKGREVISION=	1
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
