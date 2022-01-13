# $NetBSD: Makefile,v 1.7 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	singledispatch-3.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/singledispatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/singledispatch
COMMENT=	Library brings functools.singledispatch from Python 3.4
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm5
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.4+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
