# $NetBSD: buildlink3.mk,v 1.14 2018/11/12 03:51:17 ryoon Exp $

BUILDLINK_TREE+=	lasem

.if !defined(LASEM_BUILDLINK3_MK)
LASEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasem+=	lasem>=0.2.0
BUILDLINK_ABI_DEPENDS.lasem?=	lasem>=0.4.1nb13
BUILDLINK_PKGSRCDIR.lasem?=	../../graphics/lasem

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"

.endif	# LASEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasem
