# $NetBSD: Makefile,v 1.8 2009/07/02 05:23:18 epg Exp $

DISTNAME=	bzrtools-${VER}
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/1.16.0/+download/
VER=		1.16.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/bzrtools

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
