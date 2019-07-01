# $NetBSD: buildlink3.mk,v 1.1 2019/07/01 16:01:36 jaapb Exp $

BUILDLINK_TREE+=	ocaml-conduit

.if !defined(OCAML_CONDUIT_BUILDLINK3_MK)
OCAML_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-conduit+=	ocaml-conduit>=1.4.0
BUILDLINK_PKGSRCDIR.ocaml-conduit?=	../../net/ocaml-conduit

.endif	# OCAML_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-conduit
