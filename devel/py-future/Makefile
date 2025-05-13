# $NetBSD: Makefile,v 1.10 2025/05/13 10:41:02 wiz Exp $

DISTNAME=	future-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/future/}

MAINTAINER=	gde@llew.me
#HOMEPAGE=	https://python-future.org/
COMMENT=	Clean single-source support for Python 3 and 2
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# uses 'uu' and 'lib2to3' which were both removed in 3.13
#PYTHON_VERSIONS_ACCEPTED=	312 311 310

# as of 1.0.0
# 26 failed, 1024 passed, 47 skipped, 46 xfailed, 48 warnings
# with
#ALLOW_NETWORK_ACCESS=	yes
# 2 failed, 1058 passed, 37 skipped, 46 xfailed, 48 warnings

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} futurize futurize-${PYVERSSUFFIX} && \
	${MV} pasteurize pasteurize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
