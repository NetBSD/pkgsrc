# $NetBSD: Makefile,v 1.5 2024/11/11 07:28:55 wiz Exp $

DISTNAME=	hkdf-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hkdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/casebeer/python-hkdf
COMMENT=	HMAC-based Extract-and-Expand Key Derivation Function (HKDF; RFC 5869)
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
