# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 11:31:30 jaapb Exp $

BUILDLINK_TREE+=	ocaml-duff

.if !defined(OCAML_DUFF_BUILDLINK3_MK)
OCAML_DUFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-duff+=	ocaml-duff>=0.2
BUILDLINK_PKGSRCDIR.ocaml-duff?=	../../devel/ocaml-duff

.endif	# OCAML_DUFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-duff
