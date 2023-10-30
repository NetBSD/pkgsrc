# $NetBSD: Makefile,v 1.11 2023/10/30 13:58:33 pho Exp $

DISTNAME=	fsnotify-0.4.1.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for file change notification
LICENSE=	modified-bsd

# On these platforms fsnotify depends on additional packages which
# haven't been packaged yet.
BROKEN_ON_PLATFORM+=	Darwin-*-*

.include "../../mk/bsd.fast.prefs.mk"

PLIST_SRC=	PLIST.common
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
