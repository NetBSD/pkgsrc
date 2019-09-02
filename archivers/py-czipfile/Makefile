# $NetBSD: Makefile,v 1.6 2019/09/02 13:19:58 adam Exp $

DISTNAME=	czipfile-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/czipfile/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/czipfile
COMMENT=	Replacement for builtin zipfile, with fast, C-based zipfile decryption
LICENSE=	python-software-foundation

PYTHON_VERSIONS_ACCEPTED=	 27	# for 2.x only

.include "../../lang/python/egg.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
