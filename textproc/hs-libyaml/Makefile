# $NetBSD: Makefile,v 1.3 2021/05/03 19:01:16 pho Exp $

DISTNAME=	libyaml-0.1.2
PKGREVISION=	1
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
