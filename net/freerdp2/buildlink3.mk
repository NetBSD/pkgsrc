# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 18:58:53 jdolecek Exp $

BUILDLINK_TREE+=	freerdp2

.if !defined(FREERDP2_BUILDLINK3_MK)
FREERDP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freerdp2+=	freerdp2>=2.3.2
BUILDLINK_PKGSRCDIR.freerdp2?=		../../net/freerdp2
.endif	# FREERDP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freerdp2
