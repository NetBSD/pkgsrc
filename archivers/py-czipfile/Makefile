# $NetBSD: Makefile,v 1.5 2019/04/26 13:13:41 maya Exp $

DISTNAME=	czipfile-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/czipfile/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/czipfile
COMMENT=	Replacement for builtin zipfile, with fast, C-based zipfile decryption
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37	# for 2.x only

.include "../../lang/python/egg.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
