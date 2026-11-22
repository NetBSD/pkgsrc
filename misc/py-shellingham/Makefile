# $NetBSD: Makefile,v 1.8 2026/11/22 20:28:59 wiz Exp $

DISTNAME=	shellingham-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
PKGREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shellingham/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/shellingham
COMMENT=	Tool to detect surrounding shell
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

# testing needs 'make install'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
