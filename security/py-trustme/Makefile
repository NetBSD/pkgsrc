# $NetBSD: Makefile,v 1.17 2024/10/10 12:31:46 adam Exp $

DISTNAME=	trustme-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trustme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/trustme
COMMENT=	Number on quality TLS certs while you wait
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
