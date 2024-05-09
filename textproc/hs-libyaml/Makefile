# $NetBSD: Makefile,v 1.14 2024/05/09 01:32:43 pho Exp $

DISTNAME=	libyaml-0.1.4
PKGREVISION=	1
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
