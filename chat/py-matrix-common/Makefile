# $NetBSD: Makefile,v 1.10 2023/10/28 19:56:55 wiz Exp $

DISTNAME=	matrix-python-common-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-matrix-common-1.3.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	matrix-python-common
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/matrix-python-common
COMMENT=	Common utilities for Synapse, Sydent and Sygnal
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none
WHEEL_NAME=	matrix_common-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
