# $NetBSD: Makefile,v 1.12 2023/11/02 06:36:36 pho Exp $

DISTNAME=	hls-call-hierarchy-plugin-2.4.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Call hierarchy plugin for Haskell Language Server
LICENSE=	apache-2.0

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
