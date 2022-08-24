# $NetBSD: Makefile,v 1.1 2022/08/24 13:54:02 wiz Exp $

DISTNAME=	mail-parser-3.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mail-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SpamScope/mail-parser
COMMENT=	Wrapper for email standard library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.17.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-six>=1.14.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
