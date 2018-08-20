# $NetBSD: Makefile,v 1.15 2018/08/20 22:36:20 szptvlfn Exp $

DISTNAME=	sqlparse-0.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andialbrecht/sqlparse
COMMENT=	Non-validating SQL parser
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} sqlformat sqlformat-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
