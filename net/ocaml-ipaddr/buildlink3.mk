# $NetBSD: buildlink3.mk,v 1.1 2014/11/19 12:00:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ipaddr

.if !defined(OCAML_IPADDR_BUILDLINK3_MK)
OCAML_IPADDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ipaddr+=	ocaml-ipaddr>=1.0.0
BUILDLINK_PKGSRCDIR.ocaml-ipaddr?=	../../net/ocaml-ipaddr
.endif	# OCAML_IPADDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ipaddr
