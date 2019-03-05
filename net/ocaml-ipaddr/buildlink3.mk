# $NetBSD: buildlink3.mk,v 1.18 2019/03/05 18:53:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ipaddr

.if !defined(OCAML_IPADDR_BUILDLINK3_MK)
OCAML_IPADDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ipaddr+=	ocaml-ipaddr>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-ipaddr?=	ocaml-ipaddr>=3.1.0
BUILDLINK_PKGSRCDIR.ocaml-ipaddr?=	../../net/ocaml-ipaddr
BUILDLINK_FILES.ocaml-ipaddr+=		lib/ocaml/site-lib/*

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_IPADDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ipaddr
