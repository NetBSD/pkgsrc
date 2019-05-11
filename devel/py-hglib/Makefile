# $NetBSD: Makefile,v 1.8 2019/05/11 10:04:30 leot Exp $

DISTNAME=	python-hglib-2.6.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-hglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/wiki/PythonHglib
COMMENT=	Python library for interfacing with mercurial's CommandServer
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
