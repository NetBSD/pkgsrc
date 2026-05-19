# $NetBSD: Makefile,v 1.6 2026/05/19 17:52:56 adam Exp $

DISTNAME=	mail_parser-4.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mail-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SpamScope/mail-parser
COMMENT=	Wrapper for email standard library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	mail-parser

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
