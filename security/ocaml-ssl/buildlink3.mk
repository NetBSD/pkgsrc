# $NetBSD: buildlink3.mk,v 1.1 2007/03/22 10:06:24 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OCAML_SSL_BUILDLINK3_MK:=	${OCAML_SSL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ocaml-ssl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nocaml-ssl}
BUILDLINK_PACKAGES+=	ocaml-ssl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ocaml-ssl

.if ${OCAML_SSL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.4.0
BUILDLINK_PKGSRCDIR.ocaml-ssl?=	../../security/ocaml-ssl
.endif	# OCAML_SSL_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
