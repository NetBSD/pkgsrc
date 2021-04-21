# $NetBSD: buildlink3.mk,v 1.43 2021/04/21 11:40:25 adam Exp $
#

BUILDLINK_TREE+=	libscigraphica

.if !defined(LIBSCIGRAPHICA_BUILDLINK3_MK)
LIBSCIGRAPHICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libscigraphica+=	libscigraphica>=2.1.1
BUILDLINK_ABI_DEPENDS.libscigraphica+=	libscigraphica>=2.1.1nb43
BUILDLINK_PKGSRCDIR.libscigraphica?=	../../graphics/libscigraphica

.include "../../graphics/libart/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBSCIGRAPHICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libscigraphica
