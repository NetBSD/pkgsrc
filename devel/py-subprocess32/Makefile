# $NetBSD: Makefile,v 1.9 2018/06/17 09:08:48 wiz Exp $

DISTNAME=	subprocess32-3.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subprocess32/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/subprocess32
COMMENT=	Backport of the subprocess module from Python 3.2/3.3 for use on 2.x
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36	# for 2.x only

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
