# $NetBSD: buildlink3.mk,v 1.7 2020/12/04 04:56:12 riastradh Exp $
#

BUILDLINK_TREE+=	mate-polkit

.if !defined(MATE_POLKIT_BUILDLINK3_MK)
MATE_POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-polkit+=	mate-polkit>=1.8.0
BUILDLINK_ABI_DEPENDS.mate-polkit+=	mate-polkit>=1.24.0nb3
BUILDLINK_PKGSRCDIR.mate-polkit?=	../../security/mate-polkit

.include "../../security/polkit/buildlink3.mk"
.endif	# MATE_POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-polkit
