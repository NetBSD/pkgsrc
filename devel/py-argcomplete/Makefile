# $NetBSD: Makefile,v 1.27 2022/01/25 09:05:10 wiz Exp $

DISTNAME=	argcomplete-1.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argcomplete/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kislyuk/argcomplete
COMMENT=	Bash tab completion for argparse
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
