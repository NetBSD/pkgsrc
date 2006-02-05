# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:22 joerg Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBWCALC_BUILDLINK3_MK:=	${LIBWCALC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwcalc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwcalc}
BUILDLINK_PACKAGES+=	libwcalc

.if !empty(LIBWCALC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libwcalc+=	libwcalc-1.0*
BUILDLINK_RECOMMENDED.libwcalc?=	libwcalc>=1.0nb1
BUILDLINK_PKGSRCDIR.libwcalc?=	../../cad/libwcalc
.endif	# LIBWCALC_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
