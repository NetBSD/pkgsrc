# $NetBSD: buildlink3.mk,v 1.3 2009/11/16 15:29:57 stacktic Exp $

BUILDLINK_TREE+=	rump

.if !defined(RUMP_BUILDLINK3_MK)
RUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rump+=	rump>=20091108nb3
BUILDLINK_PKGSRCDIR.rump?=	../../misc/rump
.endif	# RUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rump
