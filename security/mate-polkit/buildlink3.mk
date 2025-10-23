# $NetBSD: buildlink3.mk,v 1.8 2025/10/23 20:39:09 wiz Exp $
#

BUILDLINK_TREE+=	mate-polkit

.if !defined(MATE_POLKIT_BUILDLINK3_MK)
MATE_POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-polkit+=	mate-polkit>=1.8.0
BUILDLINK_ABI_DEPENDS.mate-polkit+=	mate-polkit>=1.26.1nb14
BUILDLINK_PKGSRCDIR.mate-polkit?=	../../security/mate-polkit

.include "../../security/polkit/buildlink3.mk"
.endif	# MATE_POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-polkit
