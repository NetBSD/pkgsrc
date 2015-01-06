# $NetBSD: buildlink3.mk,v 1.20 2015/01/06 14:59:18 wiz Exp $

BUILDLINK_TREE+=	libebml

.if !defined(LIBEBML_BUILDLINK3_MK)
LIBEBML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libebml+=	libebml>=0.8
BUILDLINK_ABI_DEPENDS.libebml+=	libebml>=1.3.1
BUILDLINK_PKGSRCDIR.libebml?=	../../devel/libebml
.endif # LIBEBML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libebml
