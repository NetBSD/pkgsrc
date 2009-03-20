# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:54 joerg Exp $

BUILDLINK_TREE+=	faces

.if !defined(FACES_BUILDLINK3_MK)
FACES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faces+=	faces>=1.6.1nb1
BUILDLINK_ABI_DEPENDS.faces+=	faces>=1.6.1nb4
BUILDLINK_PKGSRCDIR.faces?=	../../mail/faces
.endif # FACES_BUILDLINK3_MK

BUILDLINK_TREE+=	-faces
