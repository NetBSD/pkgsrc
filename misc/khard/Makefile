# $NetBSD: Makefile,v 1.1 2015/04/02 22:35:34 wiz Exp $

DISTNAME=		khard-0.3.0
CATEGORIES=		misc net
MASTER_SITES=		${MASTER_SITE_GITHUB:=scheibler/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

GITHUB_TAG=		v${PKGVERSION_NOREV}
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
