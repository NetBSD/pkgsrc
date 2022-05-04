# $NetBSD: buildlink3.mk,v 1.3 2022/05/04 16:00:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_here

.if !defined(OCAML_PPX_HERE_BUILDLINK3_MK)
OCAML_PPX_HERE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_here+=	ocaml-ppx_here>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_here+=	ocaml-ppx_here>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_here?=	../../devel/ocaml-ppx_here

.endif	# OCAML_PPX_HERE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_here
