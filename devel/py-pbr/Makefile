# $NetBSD: Makefile,v 1.14 2017/01/03 13:23:02 jperkin Exp $

DISTNAME=	pbr-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pbr
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pbr \
		${DESTDIR}${PREFIX}/bin/pbr${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
