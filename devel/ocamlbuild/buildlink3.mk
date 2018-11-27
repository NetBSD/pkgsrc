# $NetBSD: buildlink3.mk,v 1.6 2018/11/27 13:59:42 jaapb Exp $

BUILDLINK_TREE+=	ocamlbuild

.if !defined(OCAMLBUILD_BUILDLINK3_MK)
OCAMLBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlbuild+=	ocamlbuild>=0.9.2
BUILDLINK_ABI_DEPENDS.ocamlbuild+=	ocamlbuild>=0.13.1
BUILDLINK_PKGSRCDIR.ocamlbuild?=	../../devel/ocamlbuild
BUILDLINK_DEPMETHOD.ocamlbuild?=	build
.endif	# OCAMLBUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlbuild
