# $NetBSD: buildlink3.mk,v 1.2 2020/04/03 14:28:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async_kernel

.if !defined(OCAML_ASYNC_KERNEL_BUILDLINK3_MK)
OCAML_ASYNC_KERNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_kernel+=	ocaml-async_kernel>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async_kernel+=	ocaml-async_kernel>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-async_kernel?=	../../devel/ocaml-async_kernel

.endif	# OCAML_ASYNC_KERNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_kernel
