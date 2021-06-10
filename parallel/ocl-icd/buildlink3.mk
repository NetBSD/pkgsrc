# $NetBSD: buildlink3.mk,v 1.1 2021/06/10 05:55:42 nia Exp $

BUILDLINK_TREE+=	ocl-icd

.if !defined(OCL_ICD_BUILDLINK3_MK)
OCL_ICD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocl-icd+=	ocl-icd>=2.3.0
BUILDLINK_PKGSRCDIR.ocl-icd?=	../../parallel/ocl-icd

.include "../../parallel/opencl-headers/buildlink3.mk"
.endif	# OCL_ICD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocl-icd
