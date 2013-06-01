# $NetBSD: buildlink3.mk,v 1.5 2013/06/01 15:42:03 stacktic Exp $

BUILDLINK_TREE+=	rump

.if !defined(RUMP_BUILDLINK3_MK)
RUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rump+=	rump>=20130601
BUILDLINK_PKGSRCDIR.rump?=	../../misc/rump
.endif	# RUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rump
