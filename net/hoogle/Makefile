# $NetBSD: Makefile,v 1.15 2024/05/09 01:32:29 pho Exp $

DISTNAME=	hoogle-5.0.18.4
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell API Search
LICENSE=	modified-bsd

# If hoogle is to be linked dynamically, it will depend on more than 160
# shared objects and the dynamic linker will spend more than a second to
# resolve symbols on startup. This is unacceptable because hoogle tends to
# be launched very frequently by editors and IDEs. This wastes storage, but
# time is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-foundation/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../www/hs-js-flot/buildlink3.mk"
.include "../../www/hs-js-jquery/buildlink3.mk"
.include "../../devel/hs-mmap/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-storable-tuple/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../www/hs-warp-tls/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
