# $NetBSD: Makefile,v 1.97 2016/05/30 10:54:57 wiz Exp $

DISTNAME=		setuptools-21.2.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://pypi.python.org/packages/5b/6e/a4bf49ddc41f144fd511f24c096dfa7600bffaf348563e08ef381dd6323e/

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

# upstream often forgets deleting files, and packages on Windows,
# so permissions are usually wrong
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*.orig

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
