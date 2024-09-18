# $NetBSD: Makefile,v 1.5 2024/09/18 08:11:22 adam Exp $

DISTNAME=	OctoPrint-FileCheck-2024.3.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-FileCheck/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FileCheck
COMMENT=	Checks for common issues in uploaded files
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
