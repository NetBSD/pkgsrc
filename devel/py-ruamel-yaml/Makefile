# $NetBSD: Makefile,v 1.9 2018/10/14 16:26:51 adam Exp $

DISTNAME=	ruamel.yaml-0.15.72
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://bitbucket.org/ruamel/yaml
COMMENT=	YAML parser/emitter
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 30
DEPENDS+=	${PYPKGPREFIX}-ruamel-ordereddict>=0.4.9:../../devel/py-ruamel-ordereddict
.endif
.if ${_PYTHON_VERSION} < 35
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
