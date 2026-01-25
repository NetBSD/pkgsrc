# $NetBSD: buildlink3.mk,v 1.1 2026/01/25 20:41:40 alnsn Exp $

BUILDLINK_TREE+=	ocaml-ounit2

.if !defined(OCAML_OUNIT2_BUILDLINK3_MK)
OCAML_OUNIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ounit2+=	ocaml-ounit2>=2.2.7
BUILDLINK_ABI_DEPENDS.ocaml-ounit2+=	ocaml-ounit2>=2.2.7
BUILDLINK_PKGSRCDIR.ocaml-ounit2?=	../../devel/ocaml-ounit2

.endif	# OCAML_OUNIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ounit2
