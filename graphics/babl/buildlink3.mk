# $NetBSD: buildlink3.mk,v 1.3 2012/05/07 08:33:26 adam Exp $

BUILDLINK_TREE+=	babl

.if !defined(BABL_BUILDLINK3_MK)
BABL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.babl+=	babl>=0.1.10
BUILDLINK_PKGSRCDIR.babl?=	../../graphics/babl

.include "../../mk/dlopen.buildlink3.mk"
.endif # BABL_BUILDLINK3_MK

BUILDLINK_TREE+=	-babl
