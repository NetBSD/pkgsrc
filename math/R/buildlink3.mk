# $NetBSD: buildlink3.mk,v 1.16 2022/06/28 11:34:35 wiz Exp $

BUILDLINK_TREE+=	R

.if !defined(R_BUILDLINK3_MK)
R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R+=	R>=1.7.0
BUILDLINK_ABI_DEPENDS.R+=	R>=4.2.0nb1
BUILDLINK_PKGSRCDIR.R?=		../../math/R

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Accelerate.framework)
.include "../../mk/blas.buildlink3.mk"
.endif
.endif # R_BUILDLINK3_MK

BUILDLINK_TREE+=	-R
