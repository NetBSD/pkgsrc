# $NetBSD: Makefile,v 1.6 2023/06/06 12:41:10 riastradh Exp $

DISTNAME=	backports.cached-property-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.cached-property/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/penguinolog/backports.cached_property
COMMENT=	Backport functools cached_property
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-backports>=1.0nb2:../../devel/py-backports

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONS_ACCEPTED=	# included in Python 3.8+

post-install:
	${RM} -f -r ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*
	${RM} -f -r ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__pycache__/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
