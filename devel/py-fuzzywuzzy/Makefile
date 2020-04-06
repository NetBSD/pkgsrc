# $NetBSD: Makefile,v 1.1 2020/04/06 08:00:19 wiz Exp $

DISTNAME=	fuzzywuzzy-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

USE_LANGUAGES=	# none

#post-install:
#	cd ${DESTDIR}${PREFIX}/bin && \
#	${MV} futurize futurize-${PYVERSSUFFIX} && \
#	${MV} pasteurize pasteurize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
