# $NetBSD: Makefile,v 1.8 2025/04/14 11:24:50 adam Exp $

DISTNAME=	dbf-0.99.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dbf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethanfurman/dbf
COMMENT=	Pure python package for reading/writing dBase, FoxPro, and Visual FoxPro .dbf files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aenum-[0-9]*:../../devel/py-aenum

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
