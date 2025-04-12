# $NetBSD: Makefile,v 1.19 2025/04/12 21:18:10 adam Exp $

DISTNAME=	pyasn1_modules-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasn1-modules/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyasn1/pyasn1-modules
COMMENT=	Modules for ITU Abstract Syntax Notification for Python
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.6.1:../../security/py-asn1

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
