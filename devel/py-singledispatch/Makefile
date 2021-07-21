# $NetBSD: Makefile,v 1.5 2021/07/21 07:12:35 adam Exp $

DISTNAME=	singledispatch-3.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/singledispatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/singledispatch
COMMENT=	Library brings functools.singledispatch from Python 3.4
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.4+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
