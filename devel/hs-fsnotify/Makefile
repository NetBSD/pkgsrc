# $NetBSD: Makefile,v 1.3 2022/01/18 02:48:08 pho Exp $

DISTNAME=	fsnotify-0.3.0.1
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for file change notification
LICENSE=	modified-bsd

# On these platforms fsnotify depends on additional packages which
# haven't been packaged yet.
BROKEN_ON_PLATFORM+=	Darwin-*-*
BROKEN_ON_PLATFORM+=	Linux-*-*

# TODO: On *BSD this package falls back on an inefficient polling
# backend as the last resort. We should consider implementing kqueue
# backend and contributing it to the upstream.

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
