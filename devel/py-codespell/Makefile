# $NetBSD: Makefile,v 1.5 2021/01/26 20:40:57 wiz Exp $

DISTNAME=	codespell-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/codespell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codespell-project/codespell
COMMENT=	Check code for common misspellings
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYTHON_VERSIONED_DEPENDENCIES+=	test:test

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/codespell \
		${DESTDIR}${PREFIX}/bin/codespell-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
