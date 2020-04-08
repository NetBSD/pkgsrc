# $NetBSD: buildlink3.mk,v 1.2 2020/04/08 09:41:35 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async_rpc_kernel

.if !defined(OCAML_ASYNC_RPC_KERNEL_BUILDLINK3_MK)
OCAML_ASYNC_RPC_KERNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_rpc_kernel+=	ocaml-async_rpc_kernel>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async_rpc_kernel+=	ocaml-async_rpc_kernel>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-async_rpc_kernel?=	../../devel/ocaml-async_rpc_kernel

.endif	# OCAML_ASYNC_RPC_KERNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_rpc_kernel
