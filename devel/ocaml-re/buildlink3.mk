# $NetBSD: buildlink3.mk,v 1.12 2020/01/24 09:14:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-re

.if !defined(OCAML_RE_BUILDLINK3_MK)
OCAML_RE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-re+=	ocaml-re>=1.6.0
BUILDLINK_ABI_DEPENDS.ocaml-re+=	ocaml-re>=1.9.0
BUILDLINK_PKGSRCDIR.ocaml-re?=		../../devel/ocaml-re
.endif	# OCAML_RE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-re
