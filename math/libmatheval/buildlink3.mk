# $NetBSD: buildlink3.mk,v 1.11 2009/12/15 21:55:05 joerg Exp $

BUILDLINK_TREE+=	libmatheval

.if !defined(LIBMATHEVAL_BUILDLINK3_MK)
LIBMATHEVAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_ABI_DEPENDS.libmatheval+=	libmatheval>=1.1.4nb2
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # LIBMATHEVAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatheval
