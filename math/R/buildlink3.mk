# $NetBSD: buildlink3.mk,v 1.13 2018/03/07 23:16:03 minskim Exp $

BUILDLINK_TREE+=	R

.if !defined(R_BUILDLINK3_MK)
R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R+=	R>=1.7.0
BUILDLINK_ABI_DEPENDS.R+=	R>=2.2.1nb2
BUILDLINK_PKGSRCDIR.R?=		../../math/R
.endif # R_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Accelerate.framework)
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-R
