# $NetBSD: buildlink3.mk,v 1.44 2020/11/05 09:07:05 ryoon Exp $

BUILDLINK_TREE+=	yaz

.if !defined(YAZ_BUILDLINK3_MK)
YAZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaz+=	yaz>=2.0
BUILDLINK_ABI_DEPENDS.yaz+=	yaz>=5.16.0nb12
BUILDLINK_PKGSRCDIR.yaz?=	../../net/yaz

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif # YAZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaz
