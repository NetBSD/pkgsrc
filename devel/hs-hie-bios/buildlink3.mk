# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:31:58 pho Exp $

BUILDLINK_TREE+=	hs-hie-bios

.if !defined(HS_HIE_BIOS_BUILDLINK3_MK)
HS_HIE_BIOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-bios+=	hs-hie-bios>=0.14.0
BUILDLINK_ABI_DEPENDS.hs-hie-bios+=	hs-hie-bios>=0.14.0nb1
BUILDLINK_PKGSRCDIR.hs-hie-bios?=	../../devel/hs-hie-bios

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../sysutils/hs-co-log-core/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.endif	# HS_HIE_BIOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-bios
