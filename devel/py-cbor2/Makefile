# $NetBSD: Makefile,v 1.11 2024/10/24 05:23:37 adam Exp $

DISTNAME=	cbor2-5.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cbor2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cbor2.readthedocs.org/
COMMENT=	CBOR (de)serializer with extensive tag support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cbor2 cbor2-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
