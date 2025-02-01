# $NetBSD: Makefile,v 1.5 2025/02/01 08:40:15 pho Exp $

DISTNAME=	git-lfs-1.2.3
CATEGORIES=	devel
DIST_SUBDIR=	hs-git-lfs # So that it won't conflict with devel/git-lfs

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell implementation of git-lfs protocol
LICENSE=	gnu-agpl-v3

.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
