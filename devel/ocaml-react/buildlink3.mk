# $NetBSD: buildlink3.mk,v 1.4 2018/04/07 10:38:59 jaapb Exp $

BUILDLINK_TREE+=	ocaml-react

.if !defined(OCAML_REACT_BUILDLINK3_MK)
OCAML_REACT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-react+=	ocaml-react>=1.2.0nb1
BUILDLINK_ABI_DEPENDS.ocaml-react+=	ocaml-react>=1.2.1nb3
BUILDLINK_PKGSRCDIR.ocaml-react?=	../../devel/ocaml-react
.endif	# OCAML_REACT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-react
