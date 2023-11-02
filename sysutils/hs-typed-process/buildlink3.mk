# $NetBSD: buildlink3.mk,v 1.12 2023/11/02 06:37:26 pho Exp $

BUILDLINK_TREE+=	hs-typed-process

.if !defined(HS_TYPED_PROCESS_BUILDLINK3_MK)
HS_TYPED_PROCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-typed-process+=	hs-typed-process>=0.2.11
BUILDLINK_ABI_DEPENDS.hs-typed-process+=	hs-typed-process>=0.2.11.1nb1
BUILDLINK_PKGSRCDIR.hs-typed-process?=		../../sysutils/hs-typed-process

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_TYPED_PROCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-typed-process
