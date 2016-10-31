# $NetBSD: Makefile,v 1.11 2016/10/31 16:31:32 wiz Exp $

DISTNAME=	sqlparse-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/sqlparse
COMMENT=	Non-validating SQL parser
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv sqlformat sqlformat-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
