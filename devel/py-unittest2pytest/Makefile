# $NetBSD: Makefile,v 1.6 2025/04/12 21:37:06 adam Exp $

DISTNAME=	unittest2pytest-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unittest2pytest/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/unittest2pytest
COMMENT=	Tool to rewrite Python unittest into pytest test cases
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} unittest2pytest unittest2pytest-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
