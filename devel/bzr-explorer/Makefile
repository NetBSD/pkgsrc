# $NetBSD: Makefile,v 1.12 2012/10/31 11:16:43 asau Exp $

DISTNAME=	bzr-explorer-${VER}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/bzr-explorer/${VER:R}/${VER}/+download/
VER=		1.2.2

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/bzr-explorer
COMMENT=	GUI frontend to bzr
LICENSE=	gnu-gpl-v2

# Needed for launchpad
FETCH_USING=	curl

USE_TOOLS+=	msgfmt

DEPENDS+=	qbzr>=0.11:../../devel/qbzr
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
