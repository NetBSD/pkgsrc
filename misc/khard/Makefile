# $NetBSD: Makefile,v 1.2 2015/07/21 19:17:51 wiz Exp $

DISTNAME=		khard-0.4.1
CATEGORIES=		misc net
MASTER_SITES=		https://pypi.python.org/packages/source/k/khard/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=		${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.0

INSTALLATION_DIRS=	share/examples/khard
REPLACE_PYTHON+=	*/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
