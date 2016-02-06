# $NetBSD: buildlink3.mk,v 1.2 2016/02/06 11:23:41 jaapb Exp $

BUILDLINK_TREE+=	ocaml-reactiveData

.if !defined(OCAML_REACTIVEDATA_BUILDLINK3_MK)
OCAML_REACTIVEDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-reactiveData+=	ocaml-reactiveData>=0.2
BUILDLINK_PKGSRCDIR.ocaml-reactiveData?=	../../devel/ocaml-reactiveData

.include "../../devel/ocaml-react/buildlink3.mk"
.endif	# OCAML_REACTIVEDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-reactiveData
