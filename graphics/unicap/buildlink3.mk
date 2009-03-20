# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:45 joerg Exp $

BUILDLINK_TREE+=	unicap

.if !defined(UNICAP_BUILDLINK3_MK)
UNICAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unicap+=	unicap>=0.9.1
BUILDLINK_ABI_DEPENDS.unicap+=	unicap>=0.9.1
BUILDLINK_PKGSRCDIR.unicap?=	../../graphics/unicap

.include "../../x11/libXv/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.endif # UNICAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-unicap
