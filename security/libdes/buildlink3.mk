# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:18 joerg Exp $

BUILDLINK_TREE+=	libdes

.if !defined(LIBDES_BUILDLINK3_MK)
LIBDES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdes+=	libdes>=4.04b
BUILDLINK_PKGSRCDIR.libdes?=	../../security/libdes
BUILDLINK_DEPMETHOD.libdes?=	build
.endif # LIBDES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdes
