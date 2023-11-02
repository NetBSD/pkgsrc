# $NetBSD: Makefile,v 1.12 2023/11/02 06:37:33 pho Exp $

DISTNAME=	libyaml-0.1.2
PKGREVISION=	9
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
