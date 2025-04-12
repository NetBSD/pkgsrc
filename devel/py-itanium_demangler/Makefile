# $NetBSD: Makefile,v 1.5 2025/04/12 11:18:39 adam Exp $

DISTNAME=	itanium_demangler-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	devel python
# PyPI does not provide source distribution files.
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_PROJECT=	python-itanium_demangler
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/python-itanium_demangler
COMMENT=	Python parser for the Itanium C++ ABI symbol mangling language
LICENSE=	0-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
