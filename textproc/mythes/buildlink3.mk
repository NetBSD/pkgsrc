# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/17 10:57:37 wiz Exp $

BUILDLINK_TREE+=	mythes

.if !defined(MYTHES_BUILDLINK3_MK)
MYTHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mythes+=	mythes>=1.2.2
BUILDLINK_PKGSRCDIR.mythes?=	../../wip/libmythes
.endif	# MYTHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mythes
