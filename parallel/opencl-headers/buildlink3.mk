# $NetBSD: buildlink3.mk,v 1.1 2021/06/09 15:19:57 nia Exp $

BUILDLINK_TREE+=	opencl-headers

.if !defined(OPENCL_HEADERS_BUILDLINK3_MK)
OPENCL_HEADERS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.opencl-headers?=	build
BUILDLINK_API_DEPENDS.opencl-headers+=	opencl-headers>=2021.04.29
BUILDLINK_PKGSRCDIR.opencl-headers?=	../../parallel/opencl-headers
.endif	# OPENCL_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-headers
