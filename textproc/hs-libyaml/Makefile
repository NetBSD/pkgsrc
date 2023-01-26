# $NetBSD: Makefile,v 1.9 2023/01/26 11:33:31 pho Exp $

DISTNAME=	libyaml-0.1.2
PKGREVISION=	6
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Low-level, streaming YAML interface
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f system-libyaml

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	resourcet

.include "../../mk/haskell.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
