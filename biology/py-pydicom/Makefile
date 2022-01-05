# $NetBSD: Makefile,v 1.7 2022/01/05 15:40:57 wiz Exp $

DISTNAME=	pydicom-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydicom/}

MAINTAINER=	eborisch@gmail.com
HOMEPAGE=	https://github.com/pydicom/pydicom
COMMENT=	Pure python package for working with DICOM files
LICENSE=	modified-bsd AND mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydicom pydicom-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
