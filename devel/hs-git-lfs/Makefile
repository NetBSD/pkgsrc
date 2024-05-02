# $NetBSD: Makefile,v 1.3 2024/05/02 08:24:44 pho Exp $

DISTNAME=	git-lfs-1.2.2
CATEGORIES=	devel
DIST_SUBDIR=	hs-git-lfs # So that it won't conflict with devel/git-lfs

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell implementation of git-lfs protocol
LICENSE=	gnu-agpl-v3

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
