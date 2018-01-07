# $NetBSD: buildlink3.mk,v 1.14 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libvisual

.if !defined(LIBVISUAL_BUILDLINK3_MK)
LIBVISUAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvisual+=	libvisual>=0.4.0
BUILDLINK_ABI_DEPENDS.libvisual+=	libvisual>=0.4.0nb3
BUILDLINK_PKGSRCDIR.libvisual?=		../../audio/libvisual

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBVISUAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvisual
