# $NetBSD: buildlink3.mk,v 1.2 2012/03/24 12:48:58 obache Exp $

BUILDLINK_TREE+=	mythes

.if !defined(MYTHES_BUILDLINK3_MK)
MYTHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mythes+=	mythes>=1.2.2
BUILDLINK_PKGSRCDIR.mythes?=	../../textproc/mythes
.endif	# MYTHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mythes
