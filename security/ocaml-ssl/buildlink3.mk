# $NetBSD: buildlink3.mk,v 1.4 2010/01/17 12:02:42 wiz Exp $

BUILDLINK_TREE+=	ocaml-ssl

.if !defined(OCAML_SSL_BUILDLINK3_MK)
OCAML_SSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.4.0
BUILDLINK_ABI_DEPENDS.ocaml-ssl?=	ocaml-ssl>=0.4.2nb1
BUILDLINK_PKGSRCDIR.ocaml-ssl?=	../../security/ocaml-ssl

.include "../../security/openssl/buildlink3.mk"
.endif # OCAML_SSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ssl
