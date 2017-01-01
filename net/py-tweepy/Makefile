# $NetBSD: Makefile,v 1.5 2017/01/01 14:43:52 wiz Exp $

DISTNAME=	tweepy-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tweepy/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.tweepy.org/
COMMENT=	A basic Python API for Twitter
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
