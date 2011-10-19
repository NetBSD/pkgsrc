# $NetBSD: buildlink3.mk,v 1.14 2011/10/19 06:50:01 obache Exp $

BUILDLINK_TREE+=	exiv2

.if !defined(EXIV2_BUILDLINK3_MK)
EXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.18
BUILDLINK_ABI_DEPENDS.exiv2+=	exiv2>=0.22
BUILDLINK_PKGSRCDIR.exiv2?=	../../graphics/exiv2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # EXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-exiv2
