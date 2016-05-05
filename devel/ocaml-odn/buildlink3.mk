# $NetBSD: buildlink3.mk,v 1.7 2016/05/05 15:32:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-odn

.if !defined(OCAML_ODN_BUILDLINK3_MK)
OCAML_ODN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-odn+=	ocaml-odn>=0.0.11
BUILDLINK_ABI_DEPENDS.ocaml-odn?=	ocaml-odn>=0.0.11nb5
BUILDLINK_PKGSRCDIR.ocaml-odn?=	../../devel/ocaml-odn

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_ODN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-odn
