# $NetBSD: buildlink3.mk,v 1.3 2017/07/21 13:45:42 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_driver

.if !defined(OCAML_PPX_DRIVER_BUILDLINK3_MK)
OCAML_PPX_DRIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_driver+=	ocaml-ppx_driver>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_driver+=	ocaml-ppx_driver>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_driver?=	../../devel/ocaml-ppx_driver

#.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.endif	# OCAML_PPX_DRIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_driver
