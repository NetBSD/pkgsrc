# $NetBSD: Makefile,v 1.12 2025/04/18 11:28:07 adam Exp $

DISTNAME=	matrix_common-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matrix-common/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/matrix-python-common
COMMENT=	Common utilities for Synapse, Sydent and Sygnal
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
