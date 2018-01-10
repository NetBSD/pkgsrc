# $NetBSD: buildlink3.mk,v 1.10 2018/01/10 16:37:41 jaapb Exp $

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=4.1.2
BUILDLINK_ABI_DEPENDS.ocamlnet+=	ocamlnet>=4.1.5
BUILDLINK_PKGSRCDIR.ocamlnet?=	../../net/ocamlnet

.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
