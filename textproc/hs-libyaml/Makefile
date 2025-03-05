# $NetBSD: Makefile,v 1.16 2025/03/05 03:40:00 pho Exp $

DISTNAME=	libyaml-0.1.4
PKGREVISION=	3
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
