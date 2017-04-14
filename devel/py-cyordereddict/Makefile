# $NetBSD: Makefile,v 1.2 2017/04/14 00:40:29 minskim Exp $

DISTNAME=	cyordereddict-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyordereddict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/shoyer/cyordereddict
COMMENT=	Cython implementation of Python's collections.OrderedDict
LICENSE=	mit

USE_LANGUAGES=	c

PLIST_VARS+=	python2

.include "../../lang/python/pyversion.mk"

.if !empty(PYVERSSUFFIX:M2.*)
PLIST.python2=	yes
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
