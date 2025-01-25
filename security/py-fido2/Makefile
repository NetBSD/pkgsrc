# $NetBSD: Makefile,v 1.10 2025/01/25 11:49:13 adam Exp $

DISTNAME=	fido2-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fido2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
# optional
DEPENDS+=	${PYPKGPREFIX}-scard>=2.0.0:../../devel/py-scard

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
