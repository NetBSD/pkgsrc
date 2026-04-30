# $NetBSD: Makefile,v 1.14 2026/04/30 11:10:10 adam Exp $

DISTNAME=	pydicom-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydicom/}

MAINTAINER=	eborisch@gmail.com
HOMEPAGE=	https://github.com/pydicom/pydicom
COMMENT=	Pure python package for working with DICOM files
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pydicom

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
