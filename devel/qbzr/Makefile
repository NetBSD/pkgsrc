# $NetBSD: Makefile,v 1.4 2009/02/09 22:56:23 joerg Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/trunk/${VER}/+download/
VER=		0.9.6

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
