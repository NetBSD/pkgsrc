# $NetBSD: buildlink3.mk,v 1.7 2014/04/16 14:11:31 wiz Exp $

BUILDLINK_TREE+=	libatomic_ops

.if !defined(LIBATOMIC_OPS_BUILDLINK3_MK)
LIBATOMIC_OPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic_ops+=	libatomic_ops>=7.4.0<2000
BUILDLINK_PKGSRCDIR.libatomic_ops?=	../../devel/libatomic_ops
.endif # LIBATOMIC_OPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libatomic_ops
