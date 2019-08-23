# $NetBSD: Makefile,v 1.12 2019/08/23 12:39:24 gdt Exp $

DISTNAME=	ruamel.yaml-0.15.100
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ruamel/yaml
COMMENT=	YAML parser/emitter
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ruamel-ordereddict>=0.4.9:../../devel/py-ruamel-ordereddict
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
