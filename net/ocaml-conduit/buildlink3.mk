# $NetBSD: buildlink3.mk,v 1.2 2020/04/08 12:46:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-conduit

.if !defined(OCAML_CONDUIT_BUILDLINK3_MK)
OCAML_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-conduit+=	ocaml-conduit>=2.0.0
BUILDLINK_ABI_DEPENDS.ocaml-conduit+=	ocaml-conduit>=2.1.0
BUILDLINK_PKGSRCDIR.ocaml-conduit?=	../../net/ocaml-conduit

.endif	# OCAML_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-conduit
