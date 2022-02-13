# $NetBSD: Makefile,v 1.31 2022/02/13 08:53:42 wiz Exp $

DISTNAME=	zfec-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zfec/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/tahoe-lafs/zfec
COMMENT=	Efficient, portable erasure coding tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-pyutil>=3.0.0:../../devel/py-pyutil
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial

PYTHON_VERSIONED_DEPENDENCIES+=	twisted:test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-argparse>=0.8:../../devel/py-argparse
.endif

REPLACE_PYTHON+=	zfec/cmdline_zfec.py
REPLACE_PYTHON+=	zfec/cmdline_zunfec.py
REPLACE_PYTHON+=	zfec/test/test_zfec.py

USE_PKG_RESOURCES=	yes

post-install:
.for bin in zfec zunfec
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
