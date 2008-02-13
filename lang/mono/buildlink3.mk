# $NetBSD: buildlink3.mk,v 1.24 2008/02/13 14:16:43 kefren Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MONO_BUILDLINK3_MK:=	${MONO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mono
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmono}
BUILDLINK_PACKAGES+=	mono
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mono

.if ${MONO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mono+=	mono>=1.2.6
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
.endif	# MONO_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
