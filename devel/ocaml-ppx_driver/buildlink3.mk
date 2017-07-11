# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 14:19:22 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_driver

.if !defined(OCAML_PPX_DRIVER_BUILDLINK3_MK)
OCAML_PPX_DRIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_driver+=	ocaml-ppx_driver>=113.24.00
BUILDLINK_ABI_DEPENDS.ocaml-ppx_driver+=	ocaml-ppx_driver>=113.45.68nb2
BUILDLINK_PKGSRCDIR.ocaml-ppx_driver?=	../../devel/ocaml-ppx_driver

#.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.endif	# OCAML_PPX_DRIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_driver
