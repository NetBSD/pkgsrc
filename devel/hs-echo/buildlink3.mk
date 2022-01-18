# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:07 pho Exp $

BUILDLINK_TREE+=	hs-echo

.if !defined(HS_ECHO_BUILDLINK3_MK)
HS_ECHO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-echo+=	hs-echo>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-echo+=	hs-echo>=0.1.4nb2
BUILDLINK_PKGSRCDIR.hs-echo?=	../../devel/hs-echo
.endif	# HS_ECHO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-echo
