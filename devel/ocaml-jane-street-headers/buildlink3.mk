# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:23 rillig Exp $

BUILDLINK_TREE+=	ocaml-jane-street-headers

.if !defined(OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK)
OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jane-street-headers+=	ocaml-jane-street-headers>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-jane-street-headers?=		../../devel/ocaml-jane-street-headers
.endif	# OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jane-street-headers
