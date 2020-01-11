# $NetBSD: Makefile,v 1.1 2020/01/11 11:04:31 pho Exp $

DISTNAME=	libyaml-0.1.1.1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Low-level, streaming YAML interface
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f system-libyaml

.include "../../mk/haskell.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
