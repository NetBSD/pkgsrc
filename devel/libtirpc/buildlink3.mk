# $NetBSD: buildlink3.mk,v 1.1 2023/08/29 11:28:40 vins Exp $

BUILDLINK_TREE+=		libtirpc

.if !defined(LIBTIRPC_BUILDLINK3_MK)
LIBTIRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtirpc+=	libtirpc>=1.3.3
BUILDLINK_PKGSRCDIR.libtirpc?=		../../devel/libtirpc

BUILDLINK_CFLAGS.libtirpc+=	-I${BUILDLINK_PREFIX.libtirpc}/include/tiprc
BUILDLINK_LDFLAGS.libtirpc+=	-ltirpc

.endif	# LIBTIRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtirpc
