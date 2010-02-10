# $NetBSD: Makefile,v 1.3 2010/02/10 19:17:35 joerg Exp $

DISTNAME=	bzr-explorer-${VER}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/bzr-explorer/trunk/${VER}/+download/
VER=		0.9.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	https://launchpad.net/bzr-explorer
COMMENT=	GUI frontend to bzr

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

DEPENDS+=	qbzr>=0.11:../../devel/qbzr
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PYDISTUTILSPKG=	yes
# only tested with 2.5
PYTHON_VERSIONS_ACCEPTED=	26 25 24

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
