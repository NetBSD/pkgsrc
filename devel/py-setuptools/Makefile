# $NetBSD: Makefile,v 1.94 2016/05/05 11:52:09 wiz Exp $

DISTNAME=		setuptools-21.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://pypi.python.org/packages/ff/d4/209f4939c49e31f5524fa0027bf1c8ec3107abaf7c61fdaad704a648c281/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/setuptools
COMMENT=		New Python packaging system
LICENSE=		python-software-foundation OR zpl-2.0

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# not sure if this would introduce a dependency cycle
#BUILD_DEPENDS+=		${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

REPLACE_PYTHON+=	setuptools/command/easy_install.py
REPLACE_PYTHON+=	setuptools/tests/test_resources.py

# upstream often forgets deleting files, and packages on Windows,
# so permissions are usually wrong
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*.orig
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/setuptools/*.tmpl

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
