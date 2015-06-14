# $NetBSD: buildlink3.mk,v 1.3 2015/06/14 10:01:41 markd Exp $

BUILDLINK_TREE+=	TECkit

.if !defined(TECKIT_BUILDLINK3_MK)
TECKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.TECkit+=	TECkit>=2.5.3
BUILDLINK_PKGSRCDIR.TECkit?=	../../converters/TECkit

.include "../../devel/zlib/buildlink3.mk"
.endif # TECKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-TECkit
