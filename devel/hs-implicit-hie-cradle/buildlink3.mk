# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:40:41 pho Exp $

BUILDLINK_TREE+=	hs-implicit-hie-cradle

.if !defined(HS_IMPLICIT_HIE_CRADLE_BUILDLINK3_MK)
HS_IMPLICIT_HIE_CRADLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-implicit-hie-cradle+=	hs-implicit-hie-cradle>=0.5.0
BUILDLINK_ABI_DEPENDS.hs-implicit-hie-cradle+=	hs-implicit-hie-cradle>=0.5.0.0nb5
BUILDLINK_PKGSRCDIR.hs-implicit-hie-cradle?=	../../devel/hs-implicit-hie-cradle

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-implicit-hie/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# HS_IMPLICIT_HIE_CRADLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-implicit-hie-cradle
