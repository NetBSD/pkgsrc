# $NetBSD: buildlink3.mk,v 1.4 2013/05/01 17:16:06 stacktic Exp $

BUILDLINK_TREE+=	rump

.if !defined(RUMP_BUILDLINK3_MK)
RUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rump+=	rump>=20130430
BUILDLINK_PKGSRCDIR.rump?=	../../misc/rump
.endif	# RUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rump
