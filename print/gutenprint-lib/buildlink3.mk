# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:14 joerg Exp $

BUILDLINK_TREE+=	gutenprint-lib

.if !defined(GUTENPRINT_LIB_BUILDLINK3_MK)
GUTENPRINT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gutenprint-lib+=	gutenprint-lib>=5.0.1
BUILDLINK_PKGSRCDIR.gutenprint-lib?=	../../print/gutenprint-lib
.endif # GUTENPRINT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gutenprint-lib
