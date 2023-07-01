# $NetBSD: buildlink3.mk,v 1.22 2023/07/01 22:13:14 wiz Exp $

BUILDLINK_TREE+=	exiv2

.if !defined(EXIV2_BUILDLINK3_MK)
EXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.27
BUILDLINK_ABI_DEPENDS.exiv2+=	exiv2>=0.28.0
BUILDLINK_PKGSRCDIR.exiv2?=	../../graphics/exiv2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/inih/buildlink3.mk"
.endif # EXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-exiv2
