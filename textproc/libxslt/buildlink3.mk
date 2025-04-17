# $NetBSD: buildlink3.mk,v 1.33 2025/04/17 21:52:36 wiz Exp $

BUILDLINK_TREE+=	libxslt

.if !defined(LIBXSLT_BUILDLINK3_MK)
LIBXSLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.8
BUILDLINK_ABI_DEPENDS.libxslt+=	libxslt>=1.1.42nb4
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBXSLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxslt
