# $NetBSD: Makefile,v 1.46 2026/06/18 08:06:20 wiz Exp $

DISTNAME=	khard-0.21.0
CATEGORIES=	misc net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/khard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lucc/khard
COMMENT=	CLI contacts application built around CardDAV
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-vobject>=0.9.4:../../textproc/py-vobject
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-argparse-[0-9]*:../../textproc/py-sphinx-argparse
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-autoapi-[0-9]*:../../textproc/py-sphinx-autoapi

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

# as of 0.21.0
# 2 failed, 403 passed, 2 xfailed, 69 warnings

INSTALLATION_DIRS=	share/examples/khard ${PKGMANDIR}/man1
REPLACE_PYTHON+=	*/*.py

pre-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} sphinx-build-${PYVERSSUFFIX} -M man source build

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/source/examples/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard
	${INSTALL_DATA} ${WRKSRC}/doc/build/man/khard.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
