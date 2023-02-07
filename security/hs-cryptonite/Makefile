# $NetBSD: Makefile,v 1.12 2023/02/07 01:41:03 pho Exp $

DISTNAME=	cryptonite-0.30
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cryptography Primitives sink
LICENSE=	modified-bsd

.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=	x86
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86=	yes
.endif

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
