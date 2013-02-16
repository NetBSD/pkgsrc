# $NetBSD: buildlink3.mk,v 1.13 2013/02/16 11:18:03 wiz Exp $

BUILDLINK_TREE+=	transfig

.if !defined(TRANSFIG_BUILDLINK3_MK)
TRANSFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.transfig+=	transfig>=3.2.4
BUILDLINK_ABI_DEPENDS.transfig+=	transfig>=3.2.5dnb1
BUILDLINK_PKGSRCDIR.transfig?=	../../print/transfig

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # TRANSFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-transfig
