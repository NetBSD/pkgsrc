# $NetBSD: buildlink3.mk,v 1.3 2015/01/20 14:24:35 jaapb Exp $

BUILDLINK_TREE+=	ocaml-oasis

.if !defined(OCAML_OASIS_BUILDLINK3_MK)
OCAML_OASIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-oasis+=	ocaml-oasis>=0.4.4
BUILDLINK_ABI_DEPENDS.ocaml-oasis?=	ocaml-oasis>=0.4.4nb2
BUILDLINK_PKGSRCDIR.ocaml-oasis?=	../../devel/ocaml-oasis

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_OASIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-oasis
