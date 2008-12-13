# $NetBSD: Makefile,v 1.1.1.1 2008/12/13 06:31:59 epg Exp $

DISTNAME=	qbzr-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/trunk/${VER}/+download/
VER=		0.9.5

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
