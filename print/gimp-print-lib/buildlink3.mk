# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GIMP_PRINT_LIB_BUILDLINK3_MK:=	${GIMP_PRINT_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp-print-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp-print-lib}
BUILDLINK_PACKAGES+=	gimp-print-lib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gimp-print-lib

.if !empty(GIMP_PRINT_LIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.5nb1
BUILDLINK_ABI_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.7nb2
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib
.endif	# GIMP_PRINT_LIB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
