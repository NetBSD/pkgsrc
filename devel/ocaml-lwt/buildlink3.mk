# $NetBSD: buildlink3.mk,v 1.2 2012/12/14 14:32:32 jaapb Exp $

BUILDLINK_TREE+=	ocamllwt

.if !defined(OCAMLLWT_BUILDLINK3_MK)
OCAMLLWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamllwt+=	ocaml-lwt>=2.4.2
BUILDLINK_PKGSRCDIR.ocamllwt?=	../../devel/ocaml-lwt

.include "../../devel/libev/buildlink3.mk"
.endif	# OCAMLLWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamllwt
