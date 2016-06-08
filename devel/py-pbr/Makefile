# $NetBSD: Makefile,v 1.12 2016/06/08 17:49:20 wiz Exp $

DISTNAME=	pbr-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pbr
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pbr \
		${DESTDIR}${PREFIX}/bin/pbr${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
