# $NetBSD: buildlink3.mk,v 1.4 2011/10/04 18:15:29 bsiegert Exp $

BUILDLINK_TREE+=	libatomic_ops

.if !defined(LIBATOMIC_OPS_BUILDLINK3_MK)
LIBATOMIC_OPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic_ops+=	libatomic_ops>=20110807
BUILDLINK_PKGSRCDIR.libatomic_ops?=	../../wip/libatomic_ops
.endif # LIBATOMIC_OPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libatomic_ops
