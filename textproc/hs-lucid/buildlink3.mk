# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:47:25 riastradh Exp $

BUILDLINK_TREE+=	hs-lucid

.if !defined(HS_LUCID_BUILDLINK3_MK)
HS_LUCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lucid+=	hs-lucid>=2.9.12
BUILDLINK_ABI_DEPENDS.hs-lucid+=	hs-lucid>=2.9.12
BUILDLINK_PKGSRCDIR.hs-lucid?=		../../textproc/hs-lucid
.endif	# HS_LUCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lucid
