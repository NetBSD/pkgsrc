# $NetBSD: Makefile,v 1.2 2023/07/25 08:31:38 adam Exp $

DISTNAME=	solc-select-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/solc-select/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crytic/solc-select
COMMENT=	Manage multiple Solidity compiler versions
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

post-install:
.for bin in solc solc-select
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
