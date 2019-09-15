# $NetBSD: buildlink3.mk,v 1.1 2019/09/15 12:55:14 nia Exp $

BUILDLINK_TREE+=	freerdp2

.if !defined(FREERDP2_BUILDLINK3_MK)
FREERDP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freerdp2+=	freerdp2>=2.0.0rc4
BUILDLINK_PKGSRCDIR.freerdp2?=		../../net/freerdp2
.endif	# FREERDP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freerdp2
