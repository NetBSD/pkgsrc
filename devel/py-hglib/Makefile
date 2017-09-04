# $NetBSD: Makefile,v 1.5 2017/09/04 18:00:52 wiz Exp $

DISTNAME=	python-hglib-1.6
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-hglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://mercurial.selenic.com/wiki/PythonHglib
COMMENT=	Python library for interfacing with mercurial's CommandServer
LICENSE=	mit

USE_LANGUAGES=	# none

EGG_NAME=	python_hglib-unknown

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
