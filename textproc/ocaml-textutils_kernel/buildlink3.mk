# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 11:08:13 jaapb Exp $

BUILDLINK_TREE+=	ocaml-textutils_kernel

.if !defined(OCAML_TEXTUTILS_KERNEL_BUILDLINK3_MK)
OCAML_TEXTUTILS_KERNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-textutils_kernel+=	ocaml-textutils_kernel>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-textutils_kernel?=	../../textproc/ocaml-textutils_kernel

.endif	# OCAML_TEXTUTILS_KERNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-textutils_kernel
