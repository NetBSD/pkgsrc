# $NetBSD: buildlink3.mk,v 1.2 2015/01/20 15:22:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-react

.if !defined(OCAML_REACT_BUILDLINK3_MK)
OCAML_REACT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-react+=	ocaml-react>=1.2.0nb1
BUILDLINK_PKGSRCDIR.ocaml-react?=	../../devel/ocaml-react
.endif	# OCAML_REACT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-react
