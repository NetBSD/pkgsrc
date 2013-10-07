# $NetBSD: buildlink3.mk,v 1.1 2013/10/07 12:53:20 obache Exp $

BUILDLINK_TREE+=	freerdp

.if !defined(FREERDP_BUILDLINK3_MK)
FREERDP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freerdp+=	freerdp>=1.0.2
BUILDLINK_PKGSRCDIR.freerdp?=	../../net/freerdp

.endif	# FREERDP_BUILDLINK3_MK

BUILDLINK_TREE+=	-freerdp
