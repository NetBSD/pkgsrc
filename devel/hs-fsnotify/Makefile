# $NetBSD: Makefile,v 1.8 2023/02/07 01:40:35 pho Exp $

DISTNAME=	fsnotify-0.4.1.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for file change notification
LICENSE=	modified-bsd

# On these platforms fsnotify depends on additional packages which
# haven't been packaged yet.
BROKEN_ON_PLATFORM+=	Darwin-*-*

PLIST_SRC+=	PLIST.common

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS:M*BSD}
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
PLIST_SRC+=	PLIST.inotify
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
