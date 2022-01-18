# $NetBSD: Makefile,v 1.4 2022/01/18 02:48:02 pho Exp $

DISTNAME=	pandoc-2.13
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Conversion between markup formats
LICENSE=	gnu-gpl-v2

# When -O2 is in effect, GHC 8.8.1 uses whopping 1 TiB of virtual
# memory (what?) to compile src/Text/Pandoc/Writers/RST.hs for some
# unknown reason, possibly related to
# https://gitlab.haskell.org/ghc/ghc/issues/5642
HASKELL_OPTIMIZATION_LEVEL=	1

# Parallelization is unsafe because of the extremely high memory
# consumption even with -O1. It uses 7.5 GiB of virtual memory even
# with no parallelism.
MAKE_JOBS_SAFE=	NO

INSTALLATION_DIRS+=		${PKGMANDIR}/man1
post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../textproc/hs-citeproc/buildlink3.mk"
.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-commonmark-pandoc/buildlink3.mk"
.include "../../net/hs-connection/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../textproc/hs-doctemplates/buildlink3.mk"
.include "../../converters/hs-emojis/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../textproc/hs-haddock-library/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../sysutils/hs-hslua-module-path/buildlink3.mk"
.include "../../devel/hs-hslua-module-system/buildlink3.mk"
.include "../../textproc/hs-hslua-module-text/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-ipynb/buildlink3.mk"
.include "../../textproc/hs-jira-wiki-markup/buildlink3.mk"
.include "../../graphics/hs-JuicyPixels/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
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
.include "../../textproc/hs-unicode-transforms/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
