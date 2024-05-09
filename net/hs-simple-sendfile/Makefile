# $NetBSD: Makefile,v 1.12 2024/05/09 01:32:31 pho Exp $

DISTNAME=	simple-sendfile-0.2.32
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Cross platform library for the sendfile system call
LICENSE=	modified-bsd

.include "../../mk/bsd.fast.prefs.mk" # for ${OPSYS}

PLIST_SRC=	PLIST.common
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Darwin"
PLIST_SRC+=	PLIST.bsd
.elif ${OPSYS} == "Linux"
PLIST_SRC+=	PLIST.linux
.else
PLIST_SRC+=	PLIST.others
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.endif

.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
