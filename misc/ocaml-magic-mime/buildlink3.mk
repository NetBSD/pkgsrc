# $NetBSD: buildlink3.mk,v 1.4 2022/05/11 11:56:46 jaapb Exp $

BUILDLINK_TREE+=	ocaml-magic-mime

.if !defined(OCAML_MAGIC_MIME_BUILDLINK3_MK)
OCAML_MAGIC_MIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-magic-mime+=	ocaml-magic-mime>=1.1.1
BUILDLINK_ABI_DEPENDS.ocaml-magic-mime+=	ocaml-magic-mime>=1.2.0
BUILDLINK_PKGSRCDIR.ocaml-magic-mime?=		../../misc/ocaml-magic-mime
.endif	# OCAML_MAGIC_MIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-magic-mime
