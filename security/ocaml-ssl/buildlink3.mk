# $NetBSD: buildlink3.mk,v 1.33 2026/03/01 12:38:38 gdt Exp $

BUILDLINK_TREE+=	ocaml-ssl

.if !defined(OCAML_SSL_BUILDLINK3_MK)
OCAML_SSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.5.8
BUILDLINK_ABI_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.5.10nb3
BUILDLINK_PKGSRCDIR.ocaml-ssl?=		../../security/ocaml-ssl

.include "../../lang/ocaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # OCAML_SSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ssl
