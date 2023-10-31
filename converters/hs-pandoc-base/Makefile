# $NetBSD: Makefile,v 1.4 2023/10/31 05:14:53 pho Exp $

.include "../../converters/hs-pandoc-base/version.mk"
DISTNAME=	pandoc-${PANDOC_BASE_VERSION}
PKGNAME=	hs-${DISTNAME:S/-/-base-/}
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pandoc document conversion library
LICENSE=	gnu-gpl-v2

# When -O2 is in effect, GHC uses whopping 3.5 GiB of memory (what?) to
# compile src/Text/Pandoc/Writers/RST.hs for some unknown reason, possibly
# related to https://gitlab.haskell.org/ghc/ghc/issues/5642
HASKELL_OPTIMIZATION_LEVEL=	1

INSTALLATION_DIRS+=		${PKGMANDIR}/man1
post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# lib:pandoc
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../textproc/hs-citeproc/buildlink3.mk"
.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-commonmark-pandoc/buildlink3.mk"
.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../textproc/hs-doctemplates/buildlink3.mk"
.include "../../converters/hs-emojis/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../textproc/hs-gridtables/buildlink3.mk"
.include "../../textproc/hs-haddock-library/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-ipynb/buildlink3.mk"
.include "../../textproc/hs-jira-wiki-markup/buildlink3.mk"
.include "../../graphics/hs-JuicyPixels/buildlink3.mk"
.include "../../net/hs-mime-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../security/hs-SHA/buildlink3.mk"
.include "../../textproc/hs-skylighting/buildlink3.mk"
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-texmath/buildlink3.mk"
.include "../../converters/hs-text-conversions/buildlink3.mk"
.include "../../textproc/hs-typst/buildlink3.mk"
.include "../../textproc/hs-unicode-collation/buildlink3.mk"
.include "../../textproc/hs-unicode-transforms/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"

# lib:xml-light
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
