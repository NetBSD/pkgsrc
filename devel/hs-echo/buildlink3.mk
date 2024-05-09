# $NetBSD: buildlink3.mk,v 1.10 2024/05/09 01:31:53 pho Exp $

BUILDLINK_TREE+=	hs-echo

.if !defined(HS_ECHO_BUILDLINK3_MK)
HS_ECHO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-echo+=	hs-echo>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-echo+=	hs-echo>=0.1.4nb8
BUILDLINK_PKGSRCDIR.hs-echo?=	../../devel/hs-echo
.endif	# HS_ECHO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-echo
