# $NetBSD: Makefile,v 1.2 2025/03/08 05:13:50 pho Exp $

DISTNAME=	hpack-0.38.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern format for Haskell packages
LICENSE=	mit

# This conflicts with archivers/hpack, which is totally unrelated to this
# package.
CONFLICTS=	hpack-[0-9]*

# Link the executable statically. Otherwise it will depend on more than 100
# shared libraries and takes too long to start up.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	NO

# lib:hpack
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-infer-license/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"

# exe:hpack
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-infer-license/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
