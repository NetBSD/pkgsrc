# $NetBSD: buildlink3.mk,v 1.2 2021/06/23 19:35:44 adam Exp $

BUILDLINK_TREE+=	hiredis

.if !defined(HIREDIS_BUILDLINK3_MK)
HIREDIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hiredis+=	hiredis>=1.0.0
BUILDLINK_PKGSRCDIR.hiredis?=	../../databases/hiredis
.endif	# HIREDIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hiredis
