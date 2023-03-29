# $NetBSD: Makefile,v 1.30 2023/03/29 09:34:05 wiz Exp $

DISTNAME=	argcomplete-1.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argcomplete/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kislyuk/argcomplete
COMMENT=	Bash tab completion for argparse
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif
PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test flake8:test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
