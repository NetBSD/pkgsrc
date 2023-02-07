# $NetBSD: Makefile,v 1.13 2023/02/07 01:40:24 pho Exp $

PKGREVISION= 1
.include "../../converters/hs-pandoc-base/version.mk"
# This package does not use the version number of "pandoc-cli" for a
# historical reason. When the upstream releases a new version of
# "pandoc-cli" without releasing new "pandoc", bump the revision of this
# package without changing PANDOC_BASE_VERSION.
DISTNAME=	pandoc-cli-0.1
PKGNAME=	pandoc-${PANDOC_BASE_VERSION}
CATEGORIES=	converters

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Conversion between markup formats
LICENSE=	gnu-gpl-v2

# If pandoc is to be linked dynamically, it will depend on more than 180
# shared objects and the dynamic linker will spend several seconds to
# resolve symbols on startup. This is unacceptable because pandoc tends to
# be launched very frequently by build systems and editors. This wastes
# storage, but time is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

.include "options.mk"

.include "../../converters/hs-pandoc-base/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
