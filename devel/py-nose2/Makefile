# $NetBSD: Makefile,v 1.18 2025/04/12 12:08:14 adam Exp $

DISTNAME=	nose2-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nose-devs/nose2
COMMENT=	Next generation of nicer testing for Python
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# coverage_plugin
DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4.1:../../devel/py-coverage

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} nose2 nose2-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
