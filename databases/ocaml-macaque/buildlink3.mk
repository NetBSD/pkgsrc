# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:51:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-macaque

.if !defined(OCAML_MACAQUE_BUILDLINK3_MK)
OCAML_MACAQUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-macaque+=	ocaml-macaque>=0.7.4
BUILDLINK_ABI_DEPENDS.ocaml-macaque+=	ocaml-macaque>=0.7.4nb4
BUILDLINK_PKGSRCDIR.ocaml-macaque?=	../../databases/ocaml-macaque

.include "../../databases/pgocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_MACAQUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-macaque
