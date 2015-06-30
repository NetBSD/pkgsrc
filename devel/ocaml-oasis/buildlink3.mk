# $NetBSD: buildlink3.mk,v 1.4 2015/06/30 11:52:57 jaapb Exp $

BUILDLINK_TREE+=	ocaml-oasis

.if !defined(OCAML_OASIS_BUILDLINK3_MK)
OCAML_OASIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-oasis+=	ocaml-oasis>=0.4.4
BUILDLINK_ABI_DEPENDS.ocaml-oasis?=	ocaml-oasis>=0.4.4nb3
BUILDLINK_PKGSRCDIR.ocaml-oasis?=	../../devel/ocaml-oasis

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_OASIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-oasis
