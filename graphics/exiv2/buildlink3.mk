# $NetBSD: buildlink3.mk,v 1.15 2012/08/01 15:30:45 drochner Exp $

BUILDLINK_TREE+=	exiv2

.if !defined(EXIV2_BUILDLINK3_MK)
EXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.18
BUILDLINK_ABI_DEPENDS.exiv2+=	exiv2>=0.23
BUILDLINK_PKGSRCDIR.exiv2?=	../../graphics/exiv2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # EXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-exiv2
