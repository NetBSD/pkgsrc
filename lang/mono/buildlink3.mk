# $NetBSD: buildlink3.mk,v 1.6 2004/04/04 16:53:59 recht Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MONO_BUILDLINK3_MK:=	${MONO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mono
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmono}
BUILDLINK_PACKAGES+=	mono

.if !empty(MONO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mono+=	mono>=0.31
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
.endif	# MONO_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
