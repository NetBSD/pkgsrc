# $NetBSD: Makefile,v 1.18 2026/06/03 09:30:20 adam Exp $

DISTNAME=	service_identity-26.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/service_identity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/service_identity
COMMENT=	Service identity verification for pyOpenSSL
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cryptography>=47:../../security/py-cryptography
# idna
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
