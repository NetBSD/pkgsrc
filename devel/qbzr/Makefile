# $NetBSD: Makefile,v 1.20 2014/05/09 07:37:03 wiz Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/${VER:R}/${VER}/+download/
VER=		0.22.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

USE_TOOLS+=	msgfmt

WRKSRC=		${WRKDIR}/qbzr

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.22.1
REPLACE_PYTHON=		lib/uifactory.py

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
