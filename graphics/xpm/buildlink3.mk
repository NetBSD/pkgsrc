# $NetBSD: buildlink3.mk,v 1.25 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	xpm

.if !defined(XPM_BUILDLINK3_MK)
XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xpm+=		xpm>=3.4k
BUILDLINK_ABI_DEPENDS.xpm+=	xpm>=3.4knb6
BUILDLINK_PKGSRCDIR.xpm?=	../../graphics/xpm

.include "../../mk/x11.buildlink3.mk"
.endif # XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xpm
