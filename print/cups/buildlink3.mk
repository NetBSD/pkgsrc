# $NetBSD: buildlink3.mk,v 1.9 2004/10/03 00:18:04 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CUPS_BUILDLINK3_MK:=	${CUPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cups
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncups}
BUILDLINK_PACKAGES+=	cups

.if !empty(CUPS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.cups+=	cups>=1.1.19nb3
BUILDLINK_RECOMMENDED.cups+=	cups>=1.1.20nb3
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups
.endif	# CUPS_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
