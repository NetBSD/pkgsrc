# $NetBSD: Makefile,v 1.14 2024/11/11 07:27:52 wiz Exp $

DISTNAME=	pyacoustid-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyacoustid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/pyacoustid
COMMENT=	Audio fingerprinting
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-audioread-[0-9]*:../../audio/py-audioread
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	chromaprint-[0-9]*:../../audio/chromaprint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
