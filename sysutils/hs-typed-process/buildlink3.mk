# $NetBSD: buildlink3.mk,v 1.10 2023/10/09 04:54:47 pho Exp $

BUILDLINK_TREE+=	hs-typed-process

.if !defined(HS_TYPED_PROCESS_BUILDLINK3_MK)
HS_TYPED_PROCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-typed-process+=	hs-typed-process>=0.2.10
BUILDLINK_ABI_DEPENDS.hs-typed-process+=	hs-typed-process>=0.2.10.1nb3
BUILDLINK_PKGSRCDIR.hs-typed-process?=		../../sysutils/hs-typed-process

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_TYPED_PROCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-typed-process
