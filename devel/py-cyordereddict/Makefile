# $NetBSD: Makefile,v 1.3 2018/08/10 15:36:16 minskim Exp $

DISTNAME=	cyordereddict-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyordereddict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/shoyer/cyordereddict
COMMENT=	Cython implementation of Python's collections.OrderedDict
LICENSE=	mit

USE_LANGUAGES=	c

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
