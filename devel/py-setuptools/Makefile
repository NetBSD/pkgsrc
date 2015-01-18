# $NetBSD: Makefile,v 1.60 2015/01/18 17:29:01 wiz Exp $

EGG_VERSION=		12.0.1
DISTNAME=		setuptools-${EGG_VERSION}
PKGNAME=		${PYPKGPREFIX}-setuptools-${EGG_VERSION}
CATEGORIES=		devel python
MASTER_SITES=		https://pypi.python.org/packages/source/s/setuptools/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/setuptools
COMMENT=		New Python packaging system
LICENSE=		python-software-foundation OR zpl

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

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
