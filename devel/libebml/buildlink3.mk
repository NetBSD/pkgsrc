# $NetBSD: buildlink3.mk,v 1.21 2020/06/29 15:08:26 adam Exp $

BUILDLINK_TREE+=	libebml

.if !defined(LIBEBML_BUILDLINK3_MK)
LIBEBML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.8
BUILDLINK_ABI_DEPENDS.libebml+=	libebml>=1.4.0
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif # LIBEBML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libebml
