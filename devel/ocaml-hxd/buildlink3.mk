# $NetBSD: buildlink3.mk,v 1.1 2022/06/20 08:16:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-hxd

.if !defined(OCAML_HXD_BUILDLINK3_MK)
OCAML_HXD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-hxd+=	ocaml-hxd>=0.3.2
BUILDLINK_PKGSRCDIR.ocaml-hxd?=		../../devel/ocaml-hxd

.endif	# OCAML_HXD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-hxd
