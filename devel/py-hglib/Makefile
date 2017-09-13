# $NetBSD: Makefile,v 1.6 2017/09/13 06:31:33 adam Exp $

DISTNAME=	python-hglib-2.4
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-hglib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://selenic.com/repo/python-hglib
COMMENT=	Python library for interfacing with mercurial's CommandServer
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
