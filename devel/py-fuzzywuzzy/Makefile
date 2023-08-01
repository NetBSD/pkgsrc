# $NetBSD: Makefile,v 1.7 2023/08/01 23:20:40 wiz Exp $

DISTNAME=	fuzzywuzzy-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fuzzywuzzy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/seatgeek/fuzzywuzzy
COMMENT=	Fuzzy String Matching in Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Levenshtein-[0-9]*:../../textproc/py-Levenshtein
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
