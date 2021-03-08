# $NetBSD: buildlink3.mk,v 1.5 2021/03/08 20:41:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-topkg

.if !defined(OCAML_TOPKG_BUILDLINK3_MK)
OCAML_TOPKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-topkg+=	ocaml-topkg>=1.0.0
BUILDLINK_ABI_DEPENDS.ocaml-topkg+=	ocaml-topkg>=1.0.3
BUILDLINK_PKGSRCDIR.ocaml-topkg?=	../../misc/ocaml-topkg

.endif	# OCAML_TOPKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-topkg
