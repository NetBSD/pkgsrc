# $NetBSD: buildlink3.mk,v 1.4 2017/07/11 10:32:28 jaapb Exp $

BUILDLINK_TREE+=	dose3

.if !defined(DOSE3_BUILDLINK3_MK)
DOSE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dose3+=	dose3>=5.0rc2
BUILDLINK_API_DEPENDS.dose3+=	dose3>=5.0.1
BUILDLINK_PKGSRCDIR.dose3?=	../../misc/dose3

.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../misc/ocaml-cudf/buildlink3.mk"
.endif	# DOSE3_3.3_BUILDLINK3_MK

BUILDLINK_TREE+=	-dose3
