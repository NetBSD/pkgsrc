# $NetBSD: Makefile,v 1.37 2023/12/07 08:18:20 wiz Exp $

DISTNAME=	khard-0.19.1
CATEGORIES=	misc net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/khard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lucc/khard
COMMENT=	CLI contacts application built around CardDAV
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-vobject>=0.9.4:../../textproc/py-vobject
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-autoapi-[0-9]*:../../textproc/py-sphinx-autoapi
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-autodoc-typehints>=1.10:../../textproc/py-sphinx-autodoc-typehints

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS=	share/examples/khard ${PKGMANDIR}/man1
REPLACE_PYTHON+=	*/*.py

pre-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} sphinx-build-${PYVERSSUFFIX} -M man source build

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/source/examples/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard
	${INSTALL_DATA} ${WRKSRC}/doc/build/man/khard.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
