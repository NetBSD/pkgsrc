# $NetBSD: Makefile,v 1.6 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	beanstalkc-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beanstalkc/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/earl/beanstalkc
COMMENT=	Simple beanstalkd client library for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		beanstalkc.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
