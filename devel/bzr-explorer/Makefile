# $NetBSD: Makefile,v 1.21 2019/04/26 13:13:48 maya Exp $

DISTNAME=	bzr-explorer-${VER}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/bzr-explorer/${VER:R}/${VER}/+download/
VER=		1.2.2

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/bzr-explorer
COMMENT=	GUI frontend to bzr
LICENSE=	gnu-gpl-v2

DEPENDS+=	qbzr>=0.11:../../devel/qbzr
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

USE_TOOLS+=	msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # qbzr

EGG_NAME=	${DISTNAME:S/bzr-//}

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
