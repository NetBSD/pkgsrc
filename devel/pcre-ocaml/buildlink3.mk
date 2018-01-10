# $NetBSD: buildlink3.mk,v 1.6 2018/01/10 16:21:20 jaapb Exp $

BUILDLINK_TREE+=	pcre-ocaml

.if !defined(PCRE_OCAML_BUILDLINK3_MK)
PCRE_OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcre-ocaml+=	pcre-ocaml>=5.10.3nb1
BUILDLINK_ABI_DEPENDS.pcre-ocaml+=	pcre-ocaml>=7.3.4
BUILDLINK_PKGSRCDIR.pcre-ocaml?=	../../devel/pcre-ocaml

.include "../../devel/pcre/buildlink3.mk"
.endif # PCRE_OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcre-ocaml
