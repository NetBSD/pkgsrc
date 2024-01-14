# $NetBSD: buildlink3.mk,v 1.2 2024/01/14 20:07:45 schmonz Exp $

BUILDLINK_TREE+=	tlsh

.if !defined(TLSH_BUILDLINK3_MK)
TLSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tlsh+=	tlsh>=4.8.2
BUILDLINK_PKGSRCDIR.tlsh?=	../../devel/tlsh
.endif	# TLSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-tlsh
