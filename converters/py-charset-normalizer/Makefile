# $NetBSD: Makefile,v 1.27 2026/03/26 14:34:17 wiz Exp $

DISTNAME=	charset_normalizer-3.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/charset-normalizer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ousret/charset_normalizer
COMMENT=	Universal Charset Detector
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} normalizer normalizer-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
