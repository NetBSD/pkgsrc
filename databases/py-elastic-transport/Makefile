# $NetBSD: Makefile,v 1.2 2023/10/09 12:40:46 adam Exp $

DISTNAME=	elastic-transport-8.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elastic-transport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elastic-transport-python
COMMENT=	Transport classes and utilities shared among Python Elastic libraries
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.2:../../www/py-urllib3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
