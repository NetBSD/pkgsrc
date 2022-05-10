# $NetBSD: buildlink3.mk,v 1.6 2022/05/10 08:14:02 jaapb Exp $

BUILDLINK_TREE+=	ocaml-reactiveData

.if !defined(OCAML_REACTIVEDATA_BUILDLINK3_MK)
OCAML_REACTIVEDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-reactiveData+=	ocaml-reactiveData>=0.2.1
BUILDLINK_ABI_DEPENDS.ocaml-reactiveData+=	ocaml-reactiveData>=0.3
BUILDLINK_PKGSRCDIR.ocaml-reactiveData?=	../../devel/ocaml-reactiveData

.include "../../devel/ocaml-react/buildlink3.mk"
.endif	# OCAML_REACTIVEDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-reactiveData
