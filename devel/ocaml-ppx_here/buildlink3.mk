# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 12:58:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_here

.if !defined(OCAML_PPX_HERE_BUILDLINK3_MK)
OCAML_PPX_HERE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_here+=	ocaml-ppx_here>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_here+=	ocaml-ppx_here>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_here?=	../../devel/ocaml-ppx_here

.endif	# OCAML_PPX_HERE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_here
