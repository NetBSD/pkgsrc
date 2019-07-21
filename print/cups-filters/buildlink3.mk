# $NetBSD: buildlink3.mk,v 1.13 2019/07/21 22:24:09 wiz Exp $

BUILDLINK_TREE+=	cups-filters

.if !defined(CUPS_FILTERS_BUILDLINK3_MK)
CUPS_FILTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups-filters+=	cups-filters>=1.8.2
BUILDLINK_ABI_DEPENDS.cups-filters+=	cups-filters>=1.23.0nb2
BUILDLINK_PKGSRCDIR.cups-filters?=	../../print/cups-filters

.include "../../print/cups-base/buildlink3.mk"
.endif # CUPS_FILTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups-filters
