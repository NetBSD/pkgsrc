# $NetBSD: Makefile,v 1.5 2022/01/18 02:48:24 pho Exp $

DISTNAME=	citeproc-0.3.0.9
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Generates citations and bibliography from CSL styles
LICENSE=	2-clause-bsd

CONFIGURE_ARGS+=	-fexecutable

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-rfc5051/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
