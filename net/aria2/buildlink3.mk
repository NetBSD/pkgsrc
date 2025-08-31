# $NetBSD: buildlink3.mk,v 1.1 2025/08/31 20:25:34 wiz Exp $

BUILDLINK_TREE+=	aria2

.if !defined(ARIA2_BUILDLINK3_MK)
ARIA2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aria2+=	aria2>=1.36.0nb13
BUILDLINK_PKGSRCDIR.aria2?=	../../net/aria2

#.include "../../converters/libiconv/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../net/libcares/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
.endif	# ARIA2_BUILDLINK3_MK

BUILDLINK_TREE+=	-aria2
