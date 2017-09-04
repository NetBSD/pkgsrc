# $NetBSD: Makefile,v 1.20 2017/09/04 18:08:19 wiz Exp $

DISTNAME=	zfec-1.4.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zfec/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://pypi.python.org/pypi/zfec/
COMMENT=	Fast erasure codec
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-darcsver-[0-9]*:../../devel/py-darcsver

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-pyutil>=1.3.19:../../devel/py-pyutil
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

REPLACE_INTERPRETER+=  python
REPLACE.python.old=    /usr/bin/env python
REPLACE.python.new=    ${PYTHONBIN}
REPLACE_FILES.python=  zfec/cmdline_zfec.py zfec/cmdline_zunfec.py zfec/test/test_zfec.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-darcsver

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
