# $NetBSD: Makefile,v 1.10 2023/10/30 11:07:18 pho Exp $

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

PLIST_VARS+=		inotify
PRINT_PLIST_AWK+=	/FSNotify\/Linux\./ { $$0 = "$${PLIST.inotify}" $$0 }
.if ${OPSYS} == "Linux" || ${OPSYS:M*BSD}
.  include "../../devel/hs-hinotify/buildlink3.mk"
.  include "../../devel/hs-shelly/buildlink3.mk"
PLIST.inotify=	yes
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
