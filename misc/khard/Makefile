# $NetBSD: Makefile,v 1.18 2019/07/21 08:50:44 wiz Exp $

DISTNAME=		khard-0.14.0
CATEGORIES=		misc net
# 0.14.0 is missing on pypi: https://github.com/scheibler/khard/issues/215
#MASTER_SITES=		${MASTER_SITE_PYPI:=k/khard/}
MASTER_SITES=		${MASTER_SITE_GITHUB:=scheibler/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-vobject>=0.9.4:../../textproc/py-vobject
#TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 # does not support python-2.x any longer

INSTALLATION_DIRS=	share/examples/khard
REPLACE_PYTHON+=	*/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/khard/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard
	cd ${DESTDIR}${PREFIX}/bin && ${MV} khard khard-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
