# $NetBSD: Makefile,v 1.11 2010/02/10 19:17:36 joerg Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/trunk/${VER}/+download/
VER=		0.16

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
