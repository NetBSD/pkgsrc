# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:34:20 wiz Exp $

BUILDLINK_TREE+=	faces

.if !defined(FACES_BUILDLINK3_MK)
FACES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faces+=	faces>=1.6.1nb1
BUILDLINK_ABI_DEPENDS.faces+=	faces>=1.6.1nb15
BUILDLINK_PKGSRCDIR.faces?=	../../mail/faces
.endif # FACES_BUILDLINK3_MK

BUILDLINK_TREE+=	-faces
