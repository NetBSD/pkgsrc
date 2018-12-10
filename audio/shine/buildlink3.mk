# $NetBSD: buildlink3.mk,v 1.1 2018/12/10 23:02:53 wiz Exp $

BUILDLINK_TREE+=	shine

.if !defined(SHINE_BUILDLINK3_MK)
SHINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shine+=	shine>=3.1.0
BUILDLINK_PKGSRCDIR.shine?=	../../audio/shine
.endif	# SHINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-shine
