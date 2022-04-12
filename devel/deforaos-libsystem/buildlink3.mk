# $NetBSD: buildlink3.mk,v 1.6 2022/04/12 22:56:53 khorben Exp $

BUILDLINK_TREE+=	deforaos-libsystem

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.4.3
BUILDLINK_ABI_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.4.3
BUILDLINK_PKGSRCDIR.deforaos-libsystem?=	../../devel/deforaos-libsystem

.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libsystem
