# $NetBSD: Makefile,v 1.31 2022/06/30 11:18:17 nia Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	7
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

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.22.1
REPLACE_PYTHON=		lib/uifactory.py

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
