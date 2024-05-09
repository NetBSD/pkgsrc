# $NetBSD: Makefile,v 1.13 2024/05/09 01:32:24 pho Exp $

# NOTE: spago is getting rewritten in PureScript, and this Haskell
# implementation is being phased out. We should remove this package and
# have users install the new implementation via npm when it gets mature
# and/or the old one bitrots further. It's already bitrotting.
DISTNAME=	spago-0.21.0
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=purescript/}
GITHUB_PROJECT=	spago-legacy

DISTFILES=	${DEFAULT_DISTFILES}
DIST_SUBDIR=	${PKGBASE}

# NOTE: This has to be kept in sync with ${WRKSRC}/scripts/fetch-templates
.include "../../lang/nodejs/application.mk"
.for version in 0.0.10 0.0.11
DISTFILES+=					docs-search-app-${version}.js
EXTRACT_DIR.docs-search-app-${version}.js=	${WRKSRC}/templates
SITES.docs-search-app-${version}.js=		\
	-https://github.com/purescript/purescript-docs-search/releases/download/v${version}/docs-search-app.js

DISTFILES+=					purescript-docs-search-${version}
EXTRACT_DIR.purescript-docs-search-${version}=	${WRKSRC}/templates
SITES.purescript-docs-search-${version}=	\
	-https://github.com/purescript/purescript-docs-search/releases/download/v${version}/purescript-docs-search

REPLACE_NODEJS+=	templates/purescript-docs-search-${version}
.endfor

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/purescript/spago\#readme
COMMENT=	PureScript package manager and build tool
LICENSE=	modified-bsd

# Use crypton instead of outdated cryptonite.
SUBST_CLASSES+=		crypton
SUBST_STAGE.crypton=	post-extract
SUBST_FILES.crypton=	spago.cabal
SUBST_SED.crypton=	-e 's/cryptonite/crypton/g'

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

# If spago is to be linked dynamically, it will depend on more than 200
# shared objects and the dynamic linker will spend several seconds to
# resolve symbols on startup. This is unacceptable because spago tends to
# be launched fairly frequently by build systems. This wastes storage, but
# time is more expensive than disks.
HASKELL_ENABLE_SHARED_LIBRARY=	no

# It makes no sense to build the profiling library because this package
# isn't meant to be used as a library.
HASKELL_ENABLE_LIBRARY_PROFILING=	no

# This package installs an executable that can generate shell completion
# scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# <kludge>
#   shells/fish provides its own spago.fish and conflicts with what
#   optparse-applicative generates.
OA.shell-types:=	${OA.shell-types:Nfish}
# </kludge>

.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-async-pool/buildlink3.mk"
.include "../../www/hs-bower-json/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../lang/dhall/buildlink3.mk"
.include "../../devel/hs-either/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-fsnotify/buildlink3.mk"
.include "../../devel/hs-generic-lens/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-lens-family-core/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../www/hs-open-browser/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../devel/hs-retry/buildlink3.mk"
.include "../../devel/hs-rio/buildlink3.mk"
.include "../../devel/hs-rio-orphans/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-semver-range/buildlink3.mk"
.include "../../textproc/hs-stringsearch/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-turtle/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../net/hs-uri-encode/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-versions/buildlink3.mk"
.include "../../devel/hs-with-utf8/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
