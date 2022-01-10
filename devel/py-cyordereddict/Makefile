# $NetBSD: Makefile,v 1.6 2022/01/10 21:57:35 wiz Exp $

DISTNAME=	cyordereddict-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyordereddict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/shoyer/cyordereddict
COMMENT=	Cython implementation of Python's collections.OrderedDict
LICENSE=	mit

USE_LANGUAGES=	c

# python>=3.5 has OrderedDict written in C
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
