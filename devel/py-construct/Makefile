# $NetBSD: Makefile,v 1.18 2022/01/04 20:52:58 wiz Exp $

DISTNAME=	construct-2.10.67
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/construct/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://construct.readthedocs.io/
COMMENT=	Powerful declarative parser for binary data
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
