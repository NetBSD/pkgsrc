# $NetBSD: buildlink3.mk,v 1.4 2026/01/07 08:48:35 wiz Exp $

BUILDLINK_TREE+=	libcupsfilters

.if !defined(LIBCUPSFILTERS_BUILDLINK3_MK)
LIBCUPSFILTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcupsfilters+=	libcupsfilters>=2.1.1
BUILDLINK_ABI_DEPENDS.libcupsfilters?=	libcupsfilters>=2.1.1nb4
BUILDLINK_PKGSRCDIR.libcupsfilters?=	../../print/libcupsfilters

.include "../../graphics/png/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.endif	# LIBCUPSFILTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcupsfilters
