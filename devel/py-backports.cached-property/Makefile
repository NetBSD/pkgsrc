# $NetBSD: Makefile,v 1.2 2021/12/30 13:05:29 adam Exp $

DISTNAME=	backports.cached-property-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.cached-property/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/penguinolog/backports.cached_property
COMMENT=	Backport functools cached_property
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-backports>=1.0nb2:../../devel/py-backports

PYTHON_VERSIONS_ACCEPTED=	37 # included in Python 3.8+

post-install:
	${RM} -f -r ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*
	${RM} -f -r ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__pycache__/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
