# $NetBSD: buildlink3.mk,v 1.5 2017/04/13 00:41:02 khorben Exp $

BUILDLINK_TREE+=	deforaos-libsystem

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.3.1
BUILDLINK_PKGSRCDIR.deforaos-libsystem?=	../../devel/deforaos-libsystem

.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libsystem
