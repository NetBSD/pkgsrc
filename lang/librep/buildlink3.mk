# $NetBSD: buildlink3.mk,v 1.1 2004/02/12 09:10:51 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBREP_BUILDLINK3_MK:=	${LIBREP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librep
.endif

.if !empty(LIBREP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		librep
BUILDLINK_DEPENDS.librep+=	librep>=0.16.1nb1
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep

.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../devel/gmp/buildlink3.mk"
.endif # LIBREP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
