# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/05 20:55:48 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBVISUAL_BUILDLINK3_MK:=	${LIBVISUAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libvisual
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibvisual}
BUILDLINK_PACKAGES+=	libvisual

.if !empty(LIBVISUAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libvisual+=	libvisual>=0.1.7
BUILDLINK_PKGSRCDIR.libvisual?=	../../zzz/libvisual
.endif	# LIBVISUAL_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
