# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 17:04:24 rillig Exp $

BUILDLINK_TREE+=	ocaml-magic-mime

.if !defined(OCAML_MAGIC_MIME_BUILDLINK3_MK)
OCAML_MAGIC_MIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-magic-mime+=	ocaml-magic-mime>=1.1.1
BUILDLINK_ABI_DEPENDS.ocaml-magic-mime+=	ocaml-magic-mime>=1.1.1
BUILDLINK_PKGSRCDIR.ocaml-magic-mime?=		../../misc/ocaml-magic-mime
.endif	# OCAML_MAGIC_MIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-magic-mime
