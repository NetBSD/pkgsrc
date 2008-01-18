# $NetBSD: buildlink3.mk,v 1.9 2008/01/18 05:08:20 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PANTOMIME_BUILDLINK3_MK:=	${PANTOMIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Pantomime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NPantomime}
BUILDLINK_PACKAGES+=	Pantomime
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Pantomime

.if !empty(PANTOMIME_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Pantomime+=	Pantomime>=1.1.2
BUILDLINK_ABI_DEPENDS.Pantomime+=	Pantomime>=1.1.2nb5
BUILDLINK_PKGSRCDIR.Pantomime?=	../../mail/Pantomime

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Pantomime+=	${GNUSTEP_LOCAL_ROOT:Q}/${GNUSTEP_IDIR:Q}/Pantomime

.endif	# PANTOMIME_BUILDLINK3_MK

.include "../../devel/gnustep-base/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
