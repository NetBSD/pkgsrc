# $NetBSD: buildlink3.mk,v 1.3 2022/05/03 19:30:18 jaapb Exp $

BUILDLINK_TREE+=	ocaml-rresult

.if !defined(OCAML_RRESULT_BUILDLINK3_MK)
OCAML_RRESULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-rresult+=	ocaml-rresult>=0.6.0
BUILDLINK_ABI_DEPENDS.ocaml-rresult+=	ocaml-rresult>=0.7.0
BUILDLINK_PKGSRCDIR.ocaml-rresult?=	../../devel/ocaml-rresult

.endif	# OCAML_RRESULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-rresult
