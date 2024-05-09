# $NetBSD: Makefile,v 1.14 2024/05/09 01:31:55 pho Exp $

DISTNAME=	fsnotify-0.4.1.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for file change notification
LICENSE=	modified-bsd

.include "../../mk/bsd.fast.prefs.mk"

PLIST_SRC+=	PLIST.common

.if ${OPSYS} == "Linux" || ${OPSYS:M*BSD}
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
PLIST_SRC+=	PLIST.inotify

.elif ${OPSYS} == "Darwin"
.  include "../../devel/hs-hfsevents/buildlink3.mk"
PLIST_SRC+=	PLIST.hfsevents
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
