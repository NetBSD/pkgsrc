# $NetBSD: Makefile,v 1.15 2023/11/21 18:56:13 adam Exp $

DISTNAME=	pyasn1_modules-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasn1-modules/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyasn1/pyasn1-modules
COMMENT=	Modules for ITU Abstract Syntax Notification for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.5.0:../../security/py-asn1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-asn1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
