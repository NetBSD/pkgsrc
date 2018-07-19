# $NetBSD: buildlink3.mk,v 1.3 2018/07/19 15:15:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-topkg

.if !defined(OCAML_TOPKG_BUILDLINK3_MK)
OCAML_TOPKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-topkg+=	ocaml-topkg>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-topkg+=	ocaml-topkg>=0.9.1nb2
BUILDLINK_PKGSRCDIR.ocaml-topkg?=	../../misc/ocaml-topkg

.endif	# OCAML_TOPKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-topkg
