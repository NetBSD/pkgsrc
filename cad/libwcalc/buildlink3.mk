# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:03:56 rillig Exp $
#

BUILDLINK_TREE+=	libwcalc

.if !defined(LIBWCALC_BUILDLINK3_MK)
LIBWCALC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwcalc+=	libwcalc-1.0*
BUILDLINK_ABI_DEPENDS.libwcalc+=	libwcalc>=1.0nb2
BUILDLINK_PKGSRCDIR.libwcalc?=		../../cad/libwcalc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBWCALC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwcalc
