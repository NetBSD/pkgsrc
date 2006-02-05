# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:08:43 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_OBJC_BUILDLINK3_MK:=	${GNUSTEP_OBJC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-objc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-objc}
BUILDLINK_PACKAGES+=	gnustep-objc

.if !empty(GNUSTEP_OBJC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-objc+=	gnustep-objc>=1.3.0
BUILDLINK_RECOMMENDED.gnustep-objc?=	gnustep-objc>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gnustep-objc?=	../../devel/gnustep-objc
.endif	# GNUSTEP_OBJC_BUILDLINK3_MK

.include "../../devel/gnustep-make/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
