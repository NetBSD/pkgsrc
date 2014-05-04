# $NetBSD: Makefile,v 1.44 2014/05/04 17:14:12 wiz Exp $

EGG_VERSION=		3.5
DISTNAME=		setuptools-${EGG_VERSION}
EGG_NAME=		setuptools-${EGG_VERSION}
PKGNAME=		${PYPKGPREFIX}-setuptools-${EGG_VERSION}
CATEGORIES=		devel python
MASTER_SITES=		https://pypi.python.org/packages/source/s/setuptools/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/setuptools
COMMENT=		New Python packaging system
LICENSE=		python-software-foundation OR zpl

PYDISTUTILSPKG=			yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX} PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	EGG_NAME=${EGGNAME}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/, \
			       "$${EGG_INFODIR}") }

REPLACE_PYTHON=		setuptools/command/easy_install.py
REPLACE_PYTHON+=	setuptools/tests/test_resources.py

.include "../../mk/bsd.fast.prefs.mk"

PYSETUPINSTALLARGS=	--single-version-externally-managed
.if ${_USE_DESTDIR} == "no"
PYSETUPINSTALLARGS+=	--root=/
.endif

.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.endif

# upstream often forgets deleting files, and packages on Windows,
# so permissions are usually wrong
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*.orig
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
