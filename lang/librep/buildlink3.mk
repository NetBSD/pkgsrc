# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:36 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBREP_BUILDLINK3_MK:=	${LIBREP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librep
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrep}
BUILDLINK_PACKAGES+=	librep

.if !empty(LIBREP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.librep+=	librep>=0.16.1nb1
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep

MAKE_FLAGS+=	rep_LIBTOOL=${LIBTOOL}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

.endif	# LIBREP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
