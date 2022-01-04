# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:42 wiz Exp $

DISTNAME=	dbf-0.99.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dbf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethanfurman/dbf
COMMENT=	Pure python package for reading/writing dBase, FoxPro, and Visual FoxPro .dbf files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-aenum-[0-9]*:../../devel/py-aenum

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-aenum

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
