# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:23 rillig Exp $

BUILDLINK_TREE+=	ocaml-jst-config

.if !defined(OCAML_JST_CONFIG_BUILDLINK3_MK)
OCAML_JST_CONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jst-config+=	ocaml-jst-config>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-jst-config?=		../../devel/ocaml-jst-config

.endif	# OCAML_JST_CONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jst-config
