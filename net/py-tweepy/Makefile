# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	tweepy-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tweepy/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.tweepy.org/
COMMENT=	A basic Python API for Twitter
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
