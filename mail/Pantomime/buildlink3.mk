# $NetBSD: buildlink3.mk,v 1.1 2004/04/10 23:52:37 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PANTOMIME_BUILDLINK3_MK:=	${PANTOMIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Pantomime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NPantomime}
BUILDLINK_PACKAGES+=	Pantomime

.if !empty(PANTOMIME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Pantomime+=	Pantomime>=1.1.2
BUILDLINK_PKGSRCDIR.Pantomime?=	../../mail/Pantomime

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Pantomime+=	${GNUSTEP_LOCAL_ROOT}/${GNUSTEP_IDIR}/Pantomime

.endif	# PANTOMIME_BUILDLINK3_MK

.include "../../devel/gnustep-base/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
