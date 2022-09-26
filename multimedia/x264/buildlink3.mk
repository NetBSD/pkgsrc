# $NetBSD: buildlink3.mk,v 1.1 2022/09/26 17:00:21 adam Exp $

BUILDLINK_TREE+=	x264

.if !defined(X264_BUILDLINK3_MK)
X264_BUILDLINK3_MK:=

# NOTE: When changing BUILDLINK_A[BP]I_DEPENDS.x264, please record
#	the value of X264_BUILD in x264.h along with the appropriate
#	dependency specification.  Perhaps we should incorporate this
#	into the version number and/or pkg-config file?
BUILDLINK_API_DEPENDS.x264+=	x264>=20220601 # X264_BUILD 164
BUILDLINK_ABI_DEPENDS.x264+=	x264>=20220601
BUILDLINK_PKGSRCDIR.x264?=	../../multimedia/x264
pkgbase:= x264
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.x264:Mthreads}
.  include "../../mk/pthread.buildlink3.mk"
.endif
.endif # X264_BUILDLINK3_MK

BUILDLINK_TREE+=	-x264
