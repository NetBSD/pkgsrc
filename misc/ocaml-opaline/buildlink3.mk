# $NetBSD: buildlink3.mk,v 1.6 2019/11/03 17:04:24 rillig Exp $

BUILDLINK_TREE+=	ocaml-opaline

.if !defined(OCAML_OPALINE_BUILDLINK3_MK)
OCAML_OPALINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-opaline+=	ocaml-opaline>=0.3.1
BUILDLINK_ABI_DEPENDS.ocaml-opaline+=	ocaml-opaline>=0.3.2
BUILDLINK_PKGSRCDIR.ocaml-opaline?=	../../misc/ocaml-opaline

# We only need this to install
BUILDLINK_DEPMETHOD.ocaml-opaline?=	build

.endif	# OCAML_OPALINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-opaline
