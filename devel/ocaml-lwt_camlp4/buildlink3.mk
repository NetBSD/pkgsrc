# $NetBSD: buildlink3.mk,v 1.4 2019/11/03 10:39:24 rillig Exp $

BUILDLINK_TREE+=	ocaml-lwt_camlp4

.if !defined(OCAML_LWT_CAMLP4_BUILDLINK3_MK)
OCAML_LWT_CAMLP4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt_camlp4+=	ocaml-lwt_camlp4>=20180325nb4
BUILDLINK_PKGSRCDIR.ocaml-lwt_camlp4?=		../../devel/ocaml-lwt_camlp4

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_LWT_CAMLP4_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt_camlp4
