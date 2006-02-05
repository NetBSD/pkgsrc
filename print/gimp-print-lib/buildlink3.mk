# $NetBSD: buildlink3.mk,v 1.5 2006/02/05 23:10:37 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GIMP_PRINT_LIB_BUILDLINK3_MK:=	${GIMP_PRINT_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp-print-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp-print-lib}
BUILDLINK_PACKAGES+=	gimp-print-lib

.if !empty(GIMP_PRINT_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.5nb1
BUILDLINK_RECOMMENDED.gimp-print-lib+=	gimp-print-lib>=4.2.7nb2
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib
.endif	# GIMP_PRINT_LIB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
