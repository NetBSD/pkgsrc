# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:54 pho Exp $

BUILDLINK_TREE+=	hs-safesemaphore

.if !defined(HS_SAFESEMAPHORE_BUILDLINK3_MK)
HS_SAFESEMAPHORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safesemaphore+=	hs-safesemaphore>=0.10.1
BUILDLINK_ABI_DEPENDS.hs-safesemaphore+=	hs-safesemaphore>=0.10.1nb1
BUILDLINK_PKGSRCDIR.hs-safesemaphore?=		../../devel/hs-safesemaphore
.endif	# HS_SAFESEMAPHORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safesemaphore
