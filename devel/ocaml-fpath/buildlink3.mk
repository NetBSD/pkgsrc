# $NetBSD: buildlink3.mk,v 1.3 2022/05/30 09:11:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-fpath

.if !defined(OCAML_FPATH_BUILDLINK3_MK)
OCAML_FPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fpath+=	ocaml-fpath>=0.7.2
BUILDLINK_ABI_DEPENDS.ocaml-fpath+=	ocaml-fpath>=0.7.3
BUILDLINK_PKGSRCDIR.ocaml-fpath?=	../../devel/ocaml-fpath

.endif	# OCAML_FPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fpath
