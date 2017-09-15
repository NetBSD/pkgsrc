# $NetBSD: Makefile,v 1.3 2017/09/15 12:54:31 adam Exp $

DISTNAME=	pylama-7.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3.1:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.0.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=1.5.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.5.2:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-radon-[0-9]*:../../devel/py-radon
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pylama pylama${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# UnicodeDecodeError: 'ascii' codec can't decode byte 0xc2 in position 148: ordinal not in range(128)
# https://github.com/klen/pylama/issues/93
MAKE_ENV+=	LC_ALL=en_US.UTF-8
