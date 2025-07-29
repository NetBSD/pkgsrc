# $NetBSD: Makefile,v 1.3 2025/07/29 09:30:19 dkazankov Exp $

DISTNAME=	pprintpp-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pprintpp/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/wolever/pprintpp
COMMENT=	Drop-in replacement for pprint that's actually pretty
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized>=0.6.1:../../devel/py-parameterized

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pypprint pypprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
