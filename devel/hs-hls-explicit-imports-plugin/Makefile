# $NetBSD: Makefile,v 1.4 2022/08/22 10:13:23 wiz Exp $

DISTNAME=	hls-explicit-imports-plugin-1.0.2.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Explicit imports plugin for Haskell Language Server
LICENSE=	apache-2.0

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
