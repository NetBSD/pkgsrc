# $NetBSD: buildlink3.mk,v 1.2 2004/03/06 23:46:06 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GIMP_PRINT_LIB_BUILDLINK3_MK:=	${GIMP_PRINT_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp-print-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp-print-lib}
BUILDLINK_PACKAGES+=	gimp-print-lib

.if !empty(GIMP_PRINT_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.5nb1
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib

.include "../../devel/gettext-lib/buildlink3.mk"

.endif	# GIMP_PRINT_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
