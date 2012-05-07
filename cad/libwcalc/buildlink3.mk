# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:16 dholland Exp $
#

BUILDLINK_TREE+=	libwcalc

.if !defined(LIBWCALC_BUILDLINK3_MK)
LIBWCALC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwcalc+=	libwcalc-1.0*
BUILDLINK_ABI_DEPENDS.libwcalc+=	libwcalc>=1.0nb2
BUILDLINK_PKGSRCDIR.libwcalc?=	../../cad/libwcalc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBWCALC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwcalc
