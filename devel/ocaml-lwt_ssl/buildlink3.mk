# $NetBSD: buildlink3.mk,v 1.13 2022/05/24 18:51:50 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt_ssl

.if !defined(OCAML_LWT_SSL_BUILDLINK3_MK)
OCAML_LWT_SSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt_ssl+=	ocaml-lwt_ssl>=1.1.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt_ssl?=	ocaml-lwt_ssl>=1.1.3nb2
BUILDLINK_PKGSRCDIR.ocaml-lwt_ssl?=	../../devel/ocaml-lwt_ssl

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.endif	# OCAML_LWT_SSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt_ssl
