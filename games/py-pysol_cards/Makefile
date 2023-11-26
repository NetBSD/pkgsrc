# $NetBSD: Makefile,v 1.4 2023/11/26 14:37:02 adam Exp $

DISTNAME=	pysol_cards-0.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysol-cards/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fc-solve.shlomifish.org/
COMMENT=	Deal PySol FC Cards
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-random2-[0-9]*:../../devel/py-random2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pysol_cards pysol_cards-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
