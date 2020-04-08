# $NetBSD: buildlink3.mk,v 1.1 2020/04/08 12:26:20 jaapb Exp $

BUILDLINK_TREE+=	ocaml-domain-name

.if !defined(OCAML_DOMAIN_NAME_BUILDLINK3_MK)
OCAML_DOMAIN_NAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-domain-name+=	ocaml-domain-name>=0.3.0
BUILDLINK_PKGSRCDIR.ocaml-domain-name?=		../../net/ocaml-domain-name

.endif	# OCAML_DOMAIN_NAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-domain-name
