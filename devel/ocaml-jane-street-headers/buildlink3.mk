# $NetBSD: buildlink3.mk,v 1.1 2019/03/13 11:35:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jane-street-headers

.if !defined(OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK)
OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jane-street-headers+=	ocaml-jane-street-headers>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-jane-street-headers?=	../../devel/ocaml-jane-street-headers
.endif	# OCAML_JANE_STREET_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jane-street-headers
