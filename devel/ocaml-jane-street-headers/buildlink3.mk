# $NetBSD: buildlink3.mk,v 1.3 2020/01/17 09:07:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jane-street-headers

.if !defined(OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK)
OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jane-street-headers+=	ocaml-jane-street-headers>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-jane-street-headers?=		../../devel/ocaml-jane-street-headers
.endif	# OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jane-street-headers
