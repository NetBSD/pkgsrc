# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:36 joerg Exp $

BUILDLINK_TREE+=	babl

.if !defined(BABL_BUILDLINK3_MK)
BABL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.babl+=	babl>=0.0.22
BUILDLINK_PKGSRCDIR.babl?=	../../graphics/babl

.include "../../mk/dlopen.buildlink3.mk"
.endif # BABL_BUILDLINK3_MK

BUILDLINK_TREE+=	-babl
