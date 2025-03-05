# $NetBSD: buildlink3.mk,v 1.12 2025/03/05 03:39:09 pho Exp $

BUILDLINK_TREE+=	hs-echo

.if !defined(HS_ECHO_BUILDLINK3_MK)
HS_ECHO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-echo+=	hs-echo>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-echo+=	hs-echo>=0.1.4nb10
BUILDLINK_PKGSRCDIR.hs-echo?=	../../devel/hs-echo
.endif	# HS_ECHO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-echo
