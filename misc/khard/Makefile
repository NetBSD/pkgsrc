# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:56 wiz Exp $

DISTNAME=		khard-0.9.0
PKGREVISION=		1
CATEGORIES=		misc net
MASTER_SITES=		${MASTER_SITE_PYPI:=k/khard/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=		${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.4.1

INSTALLATION_DIRS=	share/examples/khard
REPLACE_PYTHON+=	*/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/khard/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
