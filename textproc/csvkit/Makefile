# $NetBSD: Makefile,v 1.18 2023/11/07 22:38:04 wiz Exp $

DISTNAME=	csvkit-0.9.0
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wireservice/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/wireservice/csvkit
COMMENT=	Suite of utilities for converting to and working with CSV
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.7:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-dbf-[0-9]*:../../databases/py-dbf
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=2.0.3:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-xlrd>=0.9.2:../../textproc/py-xlrd
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.5.1:../../devel/py-coverage

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
