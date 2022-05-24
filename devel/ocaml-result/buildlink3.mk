# $NetBSD: buildlink3.mk,v 1.10 2022/05/24 18:51:51 jaapb Exp $

BUILDLINK_TREE+=	ocaml-result

.if !defined(OCAML_RESULT_BUILDLINK3_MK)
OCAML_RESULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-result+=	ocaml-result>=1.5
BUILDLINK_ABI_DEPENDS.ocaml-result+=	ocaml-result>=1.5nb2
BUILDLINK_PKGSRCDIR.ocaml-result?=	../../devel/ocaml-result
.endif	# OCAML_RESULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-result
