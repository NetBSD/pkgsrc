# $NetBSD: Makefile,v 1.15 2009/09/09 16:49:18 joerg Exp $
#

EGG_VERSION=		0.6c9
DISTNAME=		setuptools-${EGG_VERSION}
EGG_NAME=		setuptools-${EGG_VERSION}
PKGNAME=		${PYPKGPREFIX}-setuptools-${EGG_VERSION}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/s/setuptools/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/DevCenter/setuptools
COMMENT=		New Python packaging system

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=		yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX} PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	EGG_NAME=${EGGNAME}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/, \
			       "$${EGG_INFODIR}") }

CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/easy-install.pth

.include "../../mk/bsd.prefs.mk"

.include "../../lang/python/extension.mk"

PYSETUPINSTALLARGS=	--single-version-externally-managed
.if ${_USE_DESTDIR} == "no"
PYSETUPINSTALLARGS+=	--root=/
.endif

FILES_SUBST+=	PYSITELIB=${PREFIX}/${PYSITELIB}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PLIST_VARS+=	py24 py25

.if ${PYPKGPREFIX} == "py24"
PLIST.py24=		yes
.else
PLIST.py25=		yes
.endif

post-extract:
	chmod -R go-w ${WRKSRC}

post-build:
	${SED} -e 's,@PYTHON@,${PYTHONBIN},' \
	       -e 's,@PYPREFIX@,${PYPKGPREFIX},' \
	       -e 's,@PYSITELIB@,${PREFIX}/${PYSITELIB},' \
	       ${FILESDIR}/manage-eggs.py > ${WRKDIR}/manage-eggs.py
	${SED} -e 's,@PYTHON@,${PYTHONBIN},' \
	       -e 's,@PKGVERSION@,${EGG_VERSION},' \
	       ${FILESDIR}/easy_install.py > ${WRKDIR}/easy_install.py

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/manage-eggs.py ${DESTDIR}${PREFIX}/bin/${PYPKGPREFIX}-manage-eggs

.include "../../mk/bsd.pkg.mk"
