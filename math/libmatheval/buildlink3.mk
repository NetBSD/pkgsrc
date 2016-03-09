# $NetBSD: buildlink3.mk,v 1.13 2016/03/09 08:25:13 tnn Exp $

BUILDLINK_TREE+=	libmatheval

.if !defined(LIBMATHEVAL_BUILDLINK3_MK)
LIBMATHEVAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_ABI_DEPENDS.libmatheval+=	libmatheval>=1.1.4nb2
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval

.endif # LIBMATHEVAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatheval
