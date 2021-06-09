# $NetBSD: buildlink3.mk,v 1.1 2021/06/09 20:49:58 nia Exp $

BUILDLINK_TREE+=	opencl-clhpp

.if !defined(OPENCL_CLHPP_BUILDLINK3_MK)
OPENCL_CLHPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencl-clhpp+=	opencl-clhpp>=2.0.14
BUILDLINK_PKGSRCDIR.opencl-clhpp?=	../../parallel/opencl-clhpp
BUILDLINK_DEPMETHOD.opencl-clhpp?=	build
.endif	# OPENCL_CLHPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-clhpp
