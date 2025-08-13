# $NetBSD: Makefile,v 1.17 2025/08/13 11:07:32 pho Exp $

DISTNAME=	libyaml-0.1.4
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Low-level, streaming YAML interface
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	-f system-libyaml

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
