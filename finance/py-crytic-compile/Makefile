# $NetBSD: Makefile,v 1.5 2023/05/11 08:41:07 adam Exp $

DISTNAME=	crytic-compile-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crytic-compile/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/crytic/crytic-compile
COMMENT=	Abstraction layer for smart contract build systems
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-cbor2-[0-9]*:../../devel/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-solc-select>=1.0.2:../../lang/py-solc-select

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} crytic-compile crytic-compile-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
