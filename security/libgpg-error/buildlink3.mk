# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libgpg-error

.if !defined(LIBGPG_ERROR_BUILDLINK3_MK)
LIBGPG_ERROR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=0.6
BUILDLINK_ABI_DEPENDS.libgpg-error+=	libgpg-error>=1.0nb1
BUILDLINK_PKGSRCDIR.libgpg-error?=	../../security/libgpg-error

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBGPG_ERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgpg-error
