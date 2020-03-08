# $NetBSD: buildlink3.mk,v 1.6 2020/03/08 16:48:08 wiz Exp $
#

BUILDLINK_TREE+=	mate-polkit

.if !defined(MATE_POLKIT_BUILDLINK3_MK)
MATE_POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-polkit+=	mate-polkit>=1.8.0
BUILDLINK_ABI_DEPENDS.mate-polkit+=	mate-polkit>=1.22.0nb3
BUILDLINK_PKGSRCDIR.mate-polkit?=	../../security/mate-polkit

.include "../../security/polkit/buildlink3.mk"
.endif	# MATE_POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-polkit
