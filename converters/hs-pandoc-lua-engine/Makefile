# $NetBSD: Makefile,v 1.5 2023/11/02 06:36:13 pho Exp $

DISTNAME=	pandoc-lua-engine-0.2.1.2
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua engine to power custom pandoc conversions
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	lpeg

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-citeproc/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../textproc/hs-doctemplates/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../textproc/hs-hslua-module-doclayout/buildlink3.mk"
.include "../../sysutils/hs-hslua-module-path/buildlink3.mk"
.include "../../devel/hs-hslua-module-system/buildlink3.mk"
.include "../../textproc/hs-hslua-module-text/buildlink3.mk"
.include "../../devel/hs-hslua-module-version/buildlink3.mk"
.include "../../archivers/hs-hslua-module-zip/buildlink3.mk"
.include "../../lang/hs-hslua-repl/buildlink3.mk"
.include "../../devel/hs-lpeg/buildlink3.mk"
.include "../../converters/hs-pandoc-base/buildlink3.mk"
.include "../../devel/hs-pandoc-lua-marshal/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../security/hs-SHA/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
