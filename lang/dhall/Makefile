# $NetBSD: Makefile,v 1.11 2024/05/09 01:32:22 pho Exp $

DISTNAME=	dhall-1.42.1
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Configuration language guaranteed to terminate
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Diff	\
	ansi-terminal

# If bin/dhall is to be linked dynamically, it will depend on more than 140
# shared objects and the dynamic linker will spend more than a second to
# resolve symbols on startup. This is unacceptable because dhall tends to
# be launched very frequently by editors or IDEs. This wastes storage, but
# time is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no
# However, since dhall can also be used as a library, we still want to
# build the shared library so that downstream packages can use it.

# This package installs an executable that can generate shell completion
# scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:dhall
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-atomic-write/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../converters/hs-cborg-json/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../devel/hs-data-fix/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../graphics/hs-dotgen/buildlink3.mk"
.include "../../devel/hs-either/buildlink3.mk"
.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-lens-family-core/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../textproc/hs-parsers/buildlink3.mk"
.include "../../devel/hs-pretty-simple/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-repline/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../textproc/hs-text-manipulate/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"

# There are no additional dependencies for exe:dhall.

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
