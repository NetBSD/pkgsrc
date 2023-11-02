# $NetBSD: Makefile,v 1.2 2023/11/02 06:37:19 pho Exp $

DISTNAME=	crypto-api-0.13.3
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generic interface for cryptographic operations
LICENSE=	modified-bsd

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
