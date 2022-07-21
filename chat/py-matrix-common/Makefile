# $NetBSD: Makefile,v 1.6 2022/07/21 14:08:34 gdt Exp $

DISTNAME=	matrix-python-common-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-matrix-common-1.2.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	matrix-python-common
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/matrix-python-common
COMMENT=	Common utilities for Synapse, Sydent and Sygnal
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none
WHEEL_NAME=	matrix_common-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
