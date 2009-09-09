# $NetBSD: Makefile,v 1.9 2009/09/09 05:43:24 epg Exp $

DISTNAME=	bzrtools-${VER}
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/1.18/+download/
VER=		1.18.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/bzrtools

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
