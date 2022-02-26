# $NetBSD: Makefile,v 1.6 2022/02/26 12:33:45 pho Exp $

DISTNAME=	fsnotify-0.3.0.1
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for file change notification
LICENSE=	modified-bsd

# On these platforms fsnotify depends on additional packages which
# haven't been packaged yet.
BROKEN_ON_PLATFORM+=	Darwin-*-*

PLIST_SRC+=	PLIST.common

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || !empty(OPSYS:M*BSD)
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
PLIST_SRC+=	PLIST.inotify
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
