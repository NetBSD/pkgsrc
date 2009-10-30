# $NetBSD: buildlink3.mk,v 1.1 2009/10/30 18:25:23 stacktic Exp $

BUILDLINK_TREE+=	rump

.if !defined(RUMP_BUILDLINK3_MK)
RUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rump+=	rump>=20091030
BUILDLINK_PKGSRCDIR.rump?=	../../misc/rump
.endif	# RUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rump
