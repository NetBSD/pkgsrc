# $NetBSD: buildlink3.mk,v 1.1 2012/06/04 13:12:40 wiz Exp $

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=1.1.2nb1
BUILDLINK_PKGSRCDIR.ocamlnet?=	../../net/ocamlnet

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
