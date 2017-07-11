# $NetBSD: buildlink3.mk,v 1.1 2017/07/11 09:58:59 jaapb Exp $

BUILDLINK_TREE+=	ocaml-topkg

.if !defined(OCAML_TOPKG_BUILDLINK3_MK)
OCAML_TOPKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-topkg+=	ocaml-topkg>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-topkg?=	../../misc/ocaml-topkg

.endif	# OCAML_TOPKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-topkg
