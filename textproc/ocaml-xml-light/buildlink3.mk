# $NetBSD: buildlink3.mk,v 1.1 2018/11/29 10:45:37 jaapb Exp $

BUILDLINK_TREE+=	ocaml-xml-light

.if !defined(OCAML_XML_LIGHT_BUILDLINK3_MK)
OCAML_XML_LIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-xml-light+=	ocaml-xml-light>=2.4
BUILDLINK_PKGSRCDIR.ocaml-xml-light?=	../../textproc/ocaml-xml-light
.endif	# OCAML_XML_LIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-xml-light
