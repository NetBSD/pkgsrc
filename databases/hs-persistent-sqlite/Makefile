# $NetBSD: Makefile,v 1.16 2026/11/13 14:38:43 pho Exp $

DISTNAME=	persistent-sqlite-2.13.3.0
PKGREVISION=	12
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Backend for the persistent library using sqlite3
LICENSE=	mit

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	-f systemlib
CONFIGURE_ARGS+=	-f use-pkgconfig

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-microlens-th/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../devel/hs-persistent/buildlink3.mk"
.include "../../devel/hs-resource-pool/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
