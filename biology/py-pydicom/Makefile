# $NetBSD: Makefile,v 1.12 2025/02/23 18:55:10 wiz Exp $

DISTNAME=	pydicom-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydicom/}

MAINTAINER=	eborisch@gmail.com
HOMEPAGE=	https://github.com/pydicom/pydicom
COMMENT=	Pure python package for working with DICOM files
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydicom pydicom-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
