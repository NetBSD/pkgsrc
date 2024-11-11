# $NetBSD: Makefile,v 1.4 2024/11/11 07:28:11 wiz Exp $

DISTNAME=	itanium_demangler-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
# PyPI does not provide source distribution files.
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_PROJECT=	python-itanium_demangler
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/python-itanium_demangler
COMMENT=	Python parser for the Itanium C++ ABI symbol mangling language
LICENSE=	0-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
