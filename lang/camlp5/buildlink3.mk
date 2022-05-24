# $NetBSD: buildlink3.mk,v 1.23 2022/05/24 18:51:53 jaapb Exp $
#

BUILDLINK_TREE+=	camlp5

.if !defined(CAMLP5_BUILDLINK3_MK)
CAMLP5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlp5+=	camlp5>=7.00
BUILDLINK_ABI_DEPENDS.camlp5+=	camlp5>=7.13nb2
BUILDLINK_PKGSRCDIR.camlp5?=	../../lang/camlp5

.include "../../lang/ocaml/buildlink3.mk"
.endif # CAMLP5_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlp5
