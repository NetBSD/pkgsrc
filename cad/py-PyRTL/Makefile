# $NetBSD: Makefile,v 1.1 2019/10/05 06:19:15 ryoon Exp $

DISTNAME=	PyRTL-0.8.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_GITHUB:=UCSBarchlab/}
GITHUB_PROJECT=	PyRTL
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ucsbarchlab.github.io/PyRTL/
COMMENT=	Register-transfer-level hardware design and simulation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# 'make test' fails with 2 arithmetic FAILs.
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	c # for test

EGG_NAME=	${DISTNAME:tl}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
