# $NetBSD: buildlink3.mk,v 1.1 2021/09/11 23:44:48 nia Exp $

BUILDLINK_TREE+=	aften

.if !defined(AFTEN_BUILDLINK3_MK)
AFTEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aften+=	aften>=0.0.8
BUILDLINK_PKGSRCDIR.aften?=	../../audio/aften
.endif	# AFTEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-aften
