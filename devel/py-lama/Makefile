# $NetBSD: Makefile,v 1.1 2017/04/04 14:40:14 wiz Exp $

DISTNAME=	pylama-7.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pylama/
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-docstyle-[0-9]*:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-radon-[0-9]*:../../devel/py-radon

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pylama ${DESTDIR}${PREFIX}/bin/pylama-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# UnicodeDecodeError: 'ascii' codec can't decode byte 0xc2 in position 148: ordinal not in range(128)
# https://github.com/klen/pylama/issues/93
MAKE_ENV+=	LC_ALL=en_US.UTF-8
