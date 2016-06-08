# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:24 wiz Exp $

DISTNAME=	python-hglib-1.6
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-hglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mercurial.selenic.com/wiki/PythonHglib
COMMENT=	Python library for interfacing with mercurial's CommandServer
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # 2.7 and 3.4 only
EGG_NAME=	python_hglib-unknown

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
