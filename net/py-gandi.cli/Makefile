# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:16 wiz Exp $

GITHUB_TAG=	1.5
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-gandi.cli-${GITHUB_TAG}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gandi/}
GITHUB_PROJECT=	gandi.cli
DIST_SUBDIR=	gandi.cli
EGG_NAME=	gandi.cli-${GITHUB_TAG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/Gandi/gandi.cli
COMMENT=	Command line interface for Gandi.net
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-IP-[0-9]*:../../net/py-IP
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=0:../../devel/py-tox

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
