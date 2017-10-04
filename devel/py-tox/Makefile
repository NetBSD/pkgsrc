# $NetBSD: Makefile,v 1.7 2017/10/04 12:43:55 adam Exp $

DISTNAME=	tox-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://tox.testrun.org/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-py>=1.4.17:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.3.0<1.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=1.11.2:../../devel/py-virtualenv
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} tox tox${PYVERSSUFFIX} && \
		${MV} tox-quickstart tox-quickstart${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
