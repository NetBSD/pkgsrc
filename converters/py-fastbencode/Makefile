# $NetBSD: Makefile,v 1.9 2025/04/13 07:22:38 adam Exp $

DISTNAME=	fastbencode-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=f/fastbencode/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/fastbencode
COMMENT=	Implementation of bencode with optional fast C extensions
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
