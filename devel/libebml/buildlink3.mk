# $NetBSD: buildlink3.mk,v 1.22 2023/07/18 14:11:16 nia Exp $

BUILDLINK_TREE+=	libebml

.if !defined(LIBEBML_BUILDLINK3_MK)
LIBEBML_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++14

BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.8
BUILDLINK_ABI_DEPENDS.libebml+=	libebml>=1.4.0
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif # LIBEBML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libebml
