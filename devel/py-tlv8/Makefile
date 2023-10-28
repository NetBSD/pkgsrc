# $NetBSD: Makefile,v 1.3 2023/10/28 19:57:07 wiz Exp $

DISTNAME=	tlv8-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tlv8/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://pypi.org/project/tlv8/
COMMENT=	Type-Length-Value8 (TLV8) for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
