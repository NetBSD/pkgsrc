# $NetBSD: buildlink3.mk,v 1.1 2014/04/02 17:25:44 wiedi Exp $

BUILDLINK_TREE+=	hiredis

.if !defined(HIREDIS_BUILDLINK3_MK)
HIREDIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hiredis+=	hiredis>=0.11.0
BUILDLINK_PKGSRCDIR.hiredis?=	../../databases/hiredis
.endif	# HIREDIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hiredis
