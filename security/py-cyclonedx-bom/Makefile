# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:19 wiz Exp $

DISTNAME=	cyclonedx-bom-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-bom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python
COMMENT=	Creates CycloneDX Software Bill of Materials for Python projects
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib-[0-9]*:../../security/py-cyclonedx-python-lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-cyclonedx-python-lib

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} cyclonedx-bom cyclonedx-bom-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} cyclonedx-py cyclonedx-py-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
