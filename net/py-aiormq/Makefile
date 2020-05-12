# $NetBSD: Makefile,v 1.3 2020/05/12 08:19:04 adam Exp $

DISTNAME=	aiormq-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiormq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aiormq
COMMENT=	Pure python AMQP asynchronous client library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pamqp>=2.3.0:../../net/py-pamqp
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
