# $NetBSD: buildlink3.mk,v 1.11 2026/09/02 19:01:41 wiz Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.6.1
BUILDLINK_ABI_DEPENDS.poco+=	poco>=1.15.3nb1
BUILDLINK_PKGSRCDIR.poco?=	../../devel/poco

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
