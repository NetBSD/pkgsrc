# $NetBSD: buildlink3.mk,v 1.14 2020/01/17 10:35:12 jaapb Exp $

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=4.1.2
BUILDLINK_ABI_DEPENDS.ocamlnet+=	ocamlnet>=4.1.6nb13
BUILDLINK_PKGSRCDIR.ocamlnet?=		../../net/ocamlnet

.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
