# $NetBSD: Makefile,v 1.16 2024/05/02 11:01:13 pho Exp $

DISTNAME=	skylighting-core-0.14.1.1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Syntax highlighting library core
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-fexecutable

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
