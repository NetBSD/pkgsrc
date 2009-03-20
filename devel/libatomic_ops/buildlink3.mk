# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libatomic_ops

.if !defined(LIBATOMIC_OPS_BUILDLINK3_MK)
LIBATOMIC_OPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic_ops+=	libatomic_ops>=20081024nb1
BUILDLINK_PKGSRCDIR.libatomic_ops?=	../../devel/libatomic_ops
.endif # LIBATOMIC_OPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libatomic_ops
