# $NetBSD: buildlink3.mk,v 1.1 2017/07/21 14:04:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_metaquot

.if !defined(OCAML_PPX_METAQUOT_BUILDLINK3_MK)
OCAML_PPX_METAQUOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_metaquot+=	ocaml-ppx_metaquot>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_metaquot?=	../../devel/ocaml-ppx_metaquot

.endif	# OCAML_PPX_METAQUOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_metaquot
