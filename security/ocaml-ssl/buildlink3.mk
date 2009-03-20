# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:20 joerg Exp $

BUILDLINK_TREE+=	ocaml-ssl

.if !defined(OCAML_SSL_BUILDLINK3_MK)
OCAML_SSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.4.0
BUILDLINK_ABI_DEPENDS.ocaml-ssl?=	ocaml-ssl>=0.4.1nb1
BUILDLINK_PKGSRCDIR.ocaml-ssl?=	../../security/ocaml-ssl

.include "../../security/openssl/buildlink3.mk"
.endif # OCAML_SSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ssl
