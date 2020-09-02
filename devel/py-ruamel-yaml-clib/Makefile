# $NetBSD: Makefile,v 1.2 2020/09/02 21:42:48 wiz Exp $

DISTNAME=	ruamel.yaml.clib-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1:S/./-/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml.clib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/en/latest/
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
LICENSE=	mit

#.include "../../lang/python/pyversion.mk"
#.if ${_PYTHON_VERSION} == 27
#DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
#.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
