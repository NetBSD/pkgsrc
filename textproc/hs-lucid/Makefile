# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:54 pho Exp $

DISTNAME=	lucid-2.11.20230408
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Clear to write, read and edit DSL for HTML
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
