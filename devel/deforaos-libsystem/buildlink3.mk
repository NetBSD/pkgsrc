# $NetBSD: buildlink3.mk,v 1.3 2015/10/18 12:01:19 khorben Exp $

BUILDLINK_TREE+=	deforaos-libsystem

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.2.3
BUILDLINK_PKGSRCDIR.deforaos-libsystem?=	../../devel/deforaos-libsystem

.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libsystem
