# $NetBSD: buildlink3.mk,v 1.3 2022/05/04 16:37:41 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jst-config

.if !defined(OCAML_JST_CONFIG_BUILDLINK3_MK)
OCAML_JST_CONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jst-config+=	ocaml-jst-config>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-jst-config+=	ocaml-jst-config>=0.15.1
BUILDLINK_PKGSRCDIR.ocaml-jst-config?=		../../devel/ocaml-jst-config

.endif	# OCAML_JST_CONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jst-config
