# $NetBSD: Makefile,v 1.1 2025/03/09 07:35:55 pho Exp $

DISTNAME=	elm-0.19.1
PKGNAME=	${DISTNAME:S/elm/elm-lang/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=elm/}
GITHUB_PROJECT=	compiler
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}
DIST_SUBDIR=	elm-lang	# To avoid conflicting with mail/elm
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://elm-lang.org/
COMMENT=	Functional language that compiles to JavaScript
LICENSE=	modified-bsd

CONFLICTS=	elm-[0-9]*	# mail/elm

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	HTTP	\
	ansi-terminal	\
	ansi-wl-pprint	\
	bytestring	\
	containers	\
	http-client	\
	network

# Elm really needs to fetch files during build, because a part of it is
# implemented in Elm itself, and Elm requires Internet access to fetch
# dependencies. It has no offline modes.
ALLOW_NETWORK_ACCESS=	YES

# Fix build with ansi-wl-pprint >= 1.0.
SUBST_CLASSES+=		awp
SUBST_STAGE.awp=	post-extract
SUBST_MESSAGE.awp=	Adding a dependency on prettyprinter
SUBST_FILES.awp=	elm.cabal
SUBST_SED.awp=		-e 's/zip-archive/zip-archive, prettyprinter, text/'

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../sysutils/hs-filelock/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../lang/hs-language-glsl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-raw-strings-qq/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../security/hs-SHA/buildlink3.mk"
.include "../../www/hs-snap-core/buildlink3.mk"
.include "../../www/hs-snap-server/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
