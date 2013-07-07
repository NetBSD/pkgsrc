# $NetBSD: Makefile,v 1.25 2013/07/07 06:28:05 richard Exp $

EGG_VERSION=		0.8
DISTNAME=		setuptools-${EGG_VERSION}
EGG_NAME=		setuptools-${EGG_VERSION}
PKGNAME=		${PYPKGPREFIX}-setuptools-${EGG_VERSION}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/s/setuptools/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/DevCenter/setuptools
COMMENT=		New Python packaging system
LICENSE=		python-software-foundation OR zpl

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

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

#remove garbage old 0.6x PKG-INFO
post-extract:
	${RM} ${WRKSRC}/setuptools.egg-info/EGG-INFO/PKG-INFO
	${RMDIR} ${WRKSRC}/setuptools.egg-info/EGG-INFO

#remove .orig remnants prior to install
pre-install:
	${RM} ${WRKSRC}/setuptools.egg-info/*.orig

post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
