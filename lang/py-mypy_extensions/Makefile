# $NetBSD: Makefile,v 1.1 2018/11/28 08:14:57 adam Exp $

DISTNAME=	mypy_extensions-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy_extensions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mypy-lang.org/
COMMENT=	Experimental type system extensions
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing>=3.5.3:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
