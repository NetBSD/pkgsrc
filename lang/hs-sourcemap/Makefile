# $NetBSD: Makefile,v 1.2 2022/02/26 03:58:15 pho Exp $

DISTNAME=	sourcemap-0.1.7
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Implementation of source maps as proposed by Google and Mozilla
LICENSE=	modified-bsd

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
