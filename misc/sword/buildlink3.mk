# $NetBSD: buildlink3.mk,v 1.1 2015/03/12 13:30:28 nros Exp $

BUILDLINK_TREE+=	sword

.if !defined(SWORD_BUILDLINK3_MK)
SWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sword+=	sword>=1.7.4
BUILDLINK_PKGSRCDIR.sword?=	../../misc/sword

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# SWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-sword
