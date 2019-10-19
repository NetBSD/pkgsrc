# $NetBSD: Makefile,v 1.5 2019/10/19 17:01:54 adam Exp $

DISTNAME=	traitlets-4.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/traitlets/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ipython.org/
COMMENT=	Traitlets Python config system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
