# $NetBSD: Makefile,v 1.2 2025/07/29 08:54:39 kim Exp $

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
#TEST_DEPENDS+=	${PYPKGPREFIX}-parametrized>=0.6.1:../../devel/py-parametrized

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pypprint pypprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
