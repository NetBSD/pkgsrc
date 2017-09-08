# $NetBSD: buildlink3.mk,v 1.17 2017/09/08 09:51:23 jaapb Exp $
#

BUILDLINK_TREE+=	camlp5

.if !defined(CAMLP5_BUILDLINK3_MK)
CAMLP5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlp5+=	camlp5>=5.01
BUILDLINK_ABI_DEPENDS.camlp5+=	camlp5>=7.01nb1
BUILDLINK_PKGSRCDIR.camlp5?=	../../lang/camlp5

.include "../../lang/ocaml/buildlink3.mk"
.endif # CAMLP5_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlp5
