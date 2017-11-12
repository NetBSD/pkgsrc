# $NetBSD: buildlink3.mk,v 1.40 2017/11/12 14:10:15 khorben Exp $

BUILDLINK_TREE+=	cups

.if !defined(CUPS_BUILDLINK3_MK)
CUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups+=		cups>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups+=		cups>=2.2.2nb2
BUILDLINK_PKGSRCDIR.cups?=		../../print/cups-base

.include "../../print/cups-base/buildlink3.mk"
.endif # CUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups
