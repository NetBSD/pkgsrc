# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 11:05:46 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CUPS_BUILDLINK3_MK:=	${CUPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cups
.endif

.if !empty(CUPS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		cups
BUILDLINK_DEPENDS.cups?=	cups>=1.1.14nb1
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups

.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.endif	# CUPS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
