# $NetBSD: Makefile,v 1.7 2017/09/16 19:27:05 wiz Exp $

DISTNAME=	beanstalkc-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beanstalkc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/earl/beanstalkc
COMMENT=	Simple beanstalkd client library for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		beanstalkc.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
