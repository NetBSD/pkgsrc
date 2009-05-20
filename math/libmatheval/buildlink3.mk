# $NetBSD: buildlink3.mk,v 1.10 2009/05/20 00:58:22 wiz Exp $

BUILDLINK_TREE+=	libmatheval

.if !defined(LIBMATHEVAL_BUILDLINK3_MK)
LIBMATHEVAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_ABI_DEPENDS.libmatheval+=	libmatheval>=1.1.4nb1
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.endif # LIBMATHEVAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatheval
