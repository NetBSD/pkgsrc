# $NetBSD: buildlink3.mk,v 1.15 2020/04/23 12:28:50 jaapb Exp $

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=4.1.2
BUILDLINK_ABI_DEPENDS.ocamlnet+=	ocamlnet>=4.1.7
BUILDLINK_PKGSRCDIR.ocamlnet?=		../../net/ocamlnet

.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
