# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:36:12 wiz Exp $

BUILDLINK_TREE+=	mythes

.if !defined(MYTHES_BUILDLINK3_MK)
MYTHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mythes+=	mythes>=1.2.2
BUILDLINK_ABI_DEPENDS.mythes?=	mythes>=1.2.4nb3
BUILDLINK_PKGSRCDIR.mythes?=	../../textproc/mythes
.endif	# MYTHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mythes
