# $NetBSD: Makefile,v 1.18 2025/01/02 09:17:35 adam Exp $

DISTNAME=	trustme-1.2.1
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
