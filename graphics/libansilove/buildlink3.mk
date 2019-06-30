# $NetBSD: buildlink3.mk,v 1.1 2019/06/30 21:58:17 fcambus Exp $

BUILDLINK_TREE+=	libansilove

.if !defined(LIBANSILOVE_BUILDLINK3_MK)
LIBANSILOVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libansilove+=	libansilove>=1.1.2
BUILDLINK_PKGSRCDIR.libansilove?=	../../graphics/libansilove
.endif	# LIBANSILOVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libansilove
