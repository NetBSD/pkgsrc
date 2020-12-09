# $NetBSD: Makefile,v 1.2 2020/12/09 09:32:33 nia Exp $

DISTNAME=	crytic-compile-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=crytic/}
GITHUB_PROJECT=	crytic-compile
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/crytic/crytic-compile/
COMMENT=	Abstraction layer for smart contract build systems
LICENSE=	gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/crytic-compile \
		${DESTDIR}${PREFIX}/bin/crytic-compile-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
