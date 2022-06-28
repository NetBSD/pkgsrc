# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:28 wiz Exp $

BUILDLINK_TREE+=	gutenprint-lib

.if !defined(GUTENPRINT_LIB_BUILDLINK3_MK)
GUTENPRINT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gutenprint-lib+=	gutenprint-lib>=5.0.1
BUILDLINK_ABI_DEPENDS.gutenprint-lib?=	gutenprint-lib>=5.3.3nb16
BUILDLINK_PKGSRCDIR.gutenprint-lib?=	../../print/gutenprint-lib
.endif # GUTENPRINT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gutenprint-lib
