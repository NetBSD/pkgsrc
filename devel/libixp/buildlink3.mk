# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libixp

.if !defined(LIBIXP_BUILDLINK3_MK)
LIBIXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixp+=	libixp>=0.4
BUILDLINK_PKGSRCDIR.libixp?=	../../devel/libixp
.endif # LIBIXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixp
