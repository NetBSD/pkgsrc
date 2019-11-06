# $NetBSD: Makefile,v 1.21 2019/11/06 11:59:38 wiz Exp $

DISTNAME=		khard-0.15.1
CATEGORIES=		misc net
MASTER_SITES=		${MASTER_SITE_PYPI:=k/khard/}
#MASTER_SITES=		${MASTER_SITE_GITHUB:=scheibler/}
#GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-vobject>=0.9.4:../../textproc/py-vobject
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 # does not support python-2.x any longer

INSTALLATION_DIRS=	share/examples/khard ${PKGMANDIR}/man1
REPLACE_PYTHON+=	*/*.py
USE_TOOLS+=		gmake

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -C doc SPHINXBUILD=sphinx-build${PYVERSSUFFIX} SPHINXAPIDOC=sphinx-apidoc${PYVERSSUFFIX} man

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/khard/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard
	cd ${DESTDIR}${PREFIX}/bin && ${MV} khard khard-${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/doc/build/man/khard.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
