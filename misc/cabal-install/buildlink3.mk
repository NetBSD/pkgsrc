# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:28 pho Exp $

BUILDLINK_TREE+=	cabal-install

.if !defined(CABAL_INSTALL_BUILDLINK3_MK)
CABAL_INSTALL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cabal-install+=	cabal-install>=3.10.2
BUILDLINK_ABI_DEPENDS.cabal-install+=	cabal-install>=3.10.2.1nb1
BUILDLINK_PKGSRCDIR.cabal-install?=	../../misc/cabal-install

.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../misc/hs-cabal-install-solver/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../devel/hs-echo/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../security/hs-hackage-security/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../net/hs-resolv/buildlink3.mk"
.include "../../devel/hs-lukko/buildlink3.mk"
.endif	# CABAL_INSTALL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabal-install
