# $NetBSD: Makefile,v 1.11 2010/02/10 19:17:35 joerg Exp $

DISTNAME=	bzrtools-${VER}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/${VER}/+download/
VER=		2.0.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/bzrtools

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
