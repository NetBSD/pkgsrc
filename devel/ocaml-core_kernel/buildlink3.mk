# $NetBSD: buildlink3.mk,v 1.2 2019/06/11 09:06:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-core_kernel

.if !defined(OCAML_CORE_KERNEL_BUILDLINK3_MK)
OCAML_CORE_KERNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-core_kernel+=	ocaml-core_kernel>=0.12.2
BUILDLINK_PKGSRCDIR.ocaml-core_kernel?=	../../devel/ocaml-core_kernel

.endif	# OCAML_CORE_KERNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-core_kernel
