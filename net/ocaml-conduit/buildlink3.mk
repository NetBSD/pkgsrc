# $NetBSD: buildlink3.mk,v 1.3 2022/05/11 10:40:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-conduit

.if !defined(OCAML_CONDUIT_BUILDLINK3_MK)
OCAML_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-conduit+=	ocaml-conduit>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-conduit+=	ocaml-conduit>=5.1.0
BUILDLINK_PKGSRCDIR.ocaml-conduit?=	../../net/ocaml-conduit

.endif	# OCAML_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-conduit
