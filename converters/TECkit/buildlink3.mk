# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	TECkit

.if !defined(TECKIT_BUILDLINK3_MK)
TECKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.TECkit+=	TECkit>=2.5.1
BUILDLINK_PKGSRCDIR.TECkit?=	../../converters/TECkit

.include "../../devel/zlib/buildlink3.mk"
.endif # TECKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-TECkit
