# $NetBSD: buildlink3.mk,v 1.28 2023/08/14 05:25:24 wiz Exp $

BUILDLINK_TREE+=	libxslt

.if !defined(LIBXSLT_BUILDLINK3_MK)
LIBXSLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.8
BUILDLINK_ABI_DEPENDS.libxslt+=	libxslt>=1.1.38nb1
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBXSLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxslt
