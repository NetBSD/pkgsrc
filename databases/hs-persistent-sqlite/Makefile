# $NetBSD: Makefile,v 1.3 2023/11/08 13:18:24 wiz Exp $

DISTNAME=	persistent-sqlite-2.13.2.0
PKGREVISION=	2
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
