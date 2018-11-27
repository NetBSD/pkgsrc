# $NetBSD: buildlink3.mk,v 1.6 2018/11/27 15:37:45 jaapb Exp $

BUILDLINK_TREE+=	ocaml-result

.if !defined(OCAML_RESULT_BUILDLINK3_MK)
OCAML_RESULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-result+=	ocaml-result>=1.2
BUILDLINK_ABI_DEPENDS.ocaml-result+=	ocaml-result>=1.3nb3
BUILDLINK_PKGSRCDIR.ocaml-result?=	../../devel/ocaml-result
.endif	# OCAML_RESULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-result
