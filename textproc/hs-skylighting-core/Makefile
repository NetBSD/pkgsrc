# $NetBSD: Makefile,v 1.1 2020/01/17 17:09:07 pho Exp $

DISTNAME=	skylighting-core-0.8.3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Syntax highlighting library core
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-fsystem-pcre

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../textproc/hs-hxt//buildlink3.mk"
.include "../../devel/hs-safe//buildlink3.mk"
.include "../../devel/hs-utf8-string//buildlink3.mk"
.include "../../textproc/hs-regex-pcre//buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
