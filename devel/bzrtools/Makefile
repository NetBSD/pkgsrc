# $NetBSD: Makefile,v 1.4 2009/01/19 21:42:00 epg Exp $

DISTNAME=	bzrtools-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/${VER}/+download/
VER=		1.11.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/bzrtools

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
