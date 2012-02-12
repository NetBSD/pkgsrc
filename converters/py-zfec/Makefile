# $NetBSD: Makefile,v 1.7 2012/02/12 19:55:09 gls Exp $
#

DISTNAME=	zfec-1.4.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/z/zfec/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/zfec/
COMMENT=	Fast erasure codec
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-darcsver-[0-9]*:../../devel/py-darcsver
DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

REPLACE_INTERPRETER+=  python
REPLACE.python.old=    /usr/bin/env python
REPLACE.python.new=    ${PYTHONBIN}
REPLACE_FILES.python=  zfec/cmdline_zfec.py zfec/cmdline_zunfec.py zfec/test/test_zfec.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
