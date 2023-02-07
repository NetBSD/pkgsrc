# $NetBSD: Makefile,v 1.8 2023/02/07 01:40:39 pho Exp $

DISTNAME=	hls-fourmolu-plugin-1.1.1.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration with the Fourmolu code formatter
LICENSE=	apache-2.0

.include "../../devel/fourmolu/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
