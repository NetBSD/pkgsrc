# $NetBSD: Makefile,v 1.2 2015/06/14 21:49:04 wiz Exp $

DISTNAME=	python-hglib-1.6
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-hglib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mercurial.selenic.com/wiki/PythonHglib
COMMENT=	Python library for interfacing with mercurial's CommandServer
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # 2.7 and 3.4 only
EGG_NAME=	python_hglib-unknown

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
