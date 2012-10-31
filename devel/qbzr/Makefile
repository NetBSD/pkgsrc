# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:36 asau Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	2
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

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
