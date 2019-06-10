# $NetBSD: Makefile,v 1.17 2019/06/10 10:15:46 adam Exp $

DISTNAME=	argcomplete-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argcomplete/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/kislyuk/argcomplete
COMMENT=	Bash tab completion for argparse
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
