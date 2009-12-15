# $NetBSD: buildlink3.mk,v 1.12 2009/12/15 23:27:17 drochner Exp $

BUILDLINK_TREE+=	libmatheval

.if !defined(LIBMATHEVAL_BUILDLINK3_MK)
LIBMATHEVAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_ABI_DEPENDS.libmatheval+=	libmatheval>=1.1.4nb2
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval

.include "../../devel/flex/buildlink3.mk"
.endif # LIBMATHEVAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatheval
