# $NetBSD: Makefile,v 1.3 2022/01/04 20:53:52 wiz Exp $

DISTNAME=	crytic-compile-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
