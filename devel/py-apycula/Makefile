# $NetBSD: Makefile,v 1.3 2026/03/03 08:19:42 adam Exp $

DISTNAME=	apycula-0.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apycula/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/apicula
COMMENT=	Open Source tools for Gowin FPGAs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-crcmod-[0-9]*:../../security/py-crcmod
DEPENDS+=	${PYPKGPREFIX}-msgspec-[0-9]*:../../devel/py-msgspec
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# none

post-install:
.for c in pack pll unpack
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gowin_${c} gowin_${c}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
