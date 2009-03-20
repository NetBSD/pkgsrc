# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:14 joerg Exp $

BUILDLINK_TREE+=	gimp-print-lib

.if !defined(GIMP_PRINT_LIB_BUILDLINK3_MK)
GIMP_PRINT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.5nb1
BUILDLINK_ABI_DEPENDS.gimp-print-lib+=	gimp-print-lib>=4.2.7nb2
BUILDLINK_PKGSRCDIR.gimp-print-lib?=	../../print/gimp-print-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GIMP_PRINT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-print-lib
