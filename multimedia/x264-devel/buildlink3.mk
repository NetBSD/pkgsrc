# $NetBSD: buildlink3.mk,v 1.11 2012/11/08 19:55:56 adam Exp $

BUILDLINK_TREE+=	x264-devel

.if !defined(X264_DEVEL_BUILDLINK3_MK)
X264_DEVEL_BUILDLINK3_MK:=

###
### NOTE: When changing BUILDLINK_A[BP]I_DEPENDS.x264-devel, please record
###	  the value of X264_BUILD in x264.h along with the appropriate
###	  dependency specification.  Perhaps we should incorporate this
###	  into the version number and/or pkg-config file?
###
###	  Prior specification: x264-devel>=20060127 # X264_BUILD 44
###	  Prior specification: x264-devel>=20081217 # X264_BUILD 65
###	  Prior specification: x264-devel>=20110101 # X264_BUILD 112
###
BUILDLINK_API_DEPENDS.x264-devel+=	x264-devel>=20121107 # X264_BUILD 128
BUILDLINK_PKGSRCDIR.x264-devel?=	../../multimedia/x264-devel
pkgbase:= x264-devel
.  include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.x264-devel:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
.endif
.endif # X264_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-x264-devel
