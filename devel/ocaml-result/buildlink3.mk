# $NetBSD: buildlink3.mk,v 1.9 2020/12/09 11:07:26 jaapb Exp $

BUILDLINK_TREE+=	ocaml-result

.if !defined(OCAML_RESULT_BUILDLINK3_MK)
OCAML_RESULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-result+=	ocaml-result>=1.5
BUILDLINK_ABI_DEPENDS.ocaml-result+=	ocaml-result>=1.5
BUILDLINK_PKGSRCDIR.ocaml-result?=	../../devel/ocaml-result
.endif	# OCAML_RESULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-result
