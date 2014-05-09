# $NetBSD: Makefile,v 1.12 2014/05/09 07:36:56 wiz Exp $

DISTNAME=	zfec-1.4.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/z/zfec/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/zfec/
COMMENT=	Fast erasure codec
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-darcsver-[0-9]*:../../devel/py-darcsver
DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

REPLACE_INTERPRETER+=  python
REPLACE.python.old=    /usr/bin/env python
REPLACE.python.new=    ${PYTHONBIN}
REPLACE_FILES.python=  zfec/cmdline_zfec.py zfec/cmdline_zunfec.py zfec/test/test_zfec.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted via py-setuptools_trial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
