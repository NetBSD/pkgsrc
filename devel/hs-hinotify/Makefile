# $NetBSD: Makefile,v 1.4 2023/11/02 06:36:35 pho Exp $

DISTNAME=	hinotify-0.4.1
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell binding to inotify
LICENSE=	modified-bsd

# It works on Linux and BSDs supporting kqueue(2). The list could be
# expanded to support more BSDs, but unless we can actually test them we
# can't upstream patches.
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.  include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../devel/hs-async/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
