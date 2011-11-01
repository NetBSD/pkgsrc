# $NetBSD: buildlink3.mk,v 1.11 2011/11/01 06:01:38 sbd Exp $

BUILDLINK_TREE+=	kdegraphics4

.if !defined(KDEGRAPHICS4_BUILDLINK3_MK)
KDEGRAPHICS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics4+=	kdegraphics4>=4.1.1
BUILDLINK_ABI_DEPENDS.kdegraphics4?=	kdegraphics4>=4.5.5nb7
BUILDLINK_PKGSRCDIR.kdegraphics4?=	../../graphics/kdegraphics4

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDEGRAPHICS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics4
