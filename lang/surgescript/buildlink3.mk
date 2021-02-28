# $NetBSD: buildlink3.mk,v 1.1 2021/02/28 08:08:38 nia Exp $

BUILDLINK_TREE+=	surgescript

.if !defined(SURGESCRIPT_BUILDLINK3_MK)
SURGESCRIPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.surgescript+=	surgescript>=0.5.5
BUILDLINK_PKGSRCDIR.surgescript?=	../../lang/surgescript
.endif	# SURGESCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-surgescript
