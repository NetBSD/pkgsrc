# $NetBSD: Makefile,v 1.10 2025/04/21 05:43:17 adam Exp $

DISTNAME=	crytic_compile-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crytic-compile/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/crytic/crytic-compile
COMMENT=	Abstraction layer for smart contract build systems
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cbor2-[0-9]*:../../devel/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-solc-select>=1.0.4:../../lang/py-solc-select

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} crytic-compile crytic-compile-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
