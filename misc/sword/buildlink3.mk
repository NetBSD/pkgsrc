# $NetBSD: buildlink3.mk,v 1.36 2021/04/21 13:24:12 adam Exp $

BUILDLINK_TREE+=	sword

.if !defined(SWORD_BUILDLINK3_MK)
SWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sword+=	sword>=1.8.1
BUILDLINK_ABI_DEPENDS.sword?=	sword>=1.8.1nb11
BUILDLINK_PKGSRCDIR.sword?=	../../misc/sword

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# SWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-sword
