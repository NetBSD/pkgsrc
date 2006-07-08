# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNUSTEP_OBJC_LF2_BUILDLINK3_MK:=	${GNUSTEP_OBJC_LF2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-objc-lf2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-objc-lf2}
BUILDLINK_PACKAGES+=	gnustep-objc-lf2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnustep-objc-lf2

.if !empty(GNUSTEP_OBJC_LF2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnustep-objc-lf2+=	gnustep-objc-lf2>=2.95.3.88
BUILDLINK_ABI_DEPENDS.gnustep-objc-lf2?=	gnustep-objc-lf2>=2.95.3.88nb1
BUILDLINK_PKGSRCDIR.gnustep-objc-lf2?=	../../devel/gnustep-objc-lf2
BUILDLINK_TRANSFORM.gnustep-objc-lf2?=	-e "s|Headers/objc_lf2/|Headers/objc/|g"
BUILDLINK_TRANSFORM+=	l:objc:objc_lf2
.endif	# GNUSTEP_OBJC_LF2_BUILDLINK3_MK

.include "../../devel/gnustep-make/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
