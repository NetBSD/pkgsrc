# $NetBSD: Makefile,v 1.8 2023/02/07 01:40:24 pho Exp $

DISTNAME=	sqlite-simple-0.4.18.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mid-Level SQLite client library
LICENSE=	modified-bsd

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-blaze-textual/buildlink3.mk"
.include "../../databases/hs-direct-sqlite/buildlink3.mk"
.include "../../devel/hs-Only/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
