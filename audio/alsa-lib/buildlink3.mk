# $NetBSD: buildlink3.mk,v 1.2 2009/01/28 05:38:53 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ALSA_LIB_BUILDLINK3_MK:=	${ALSA_LIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	alsa-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nalsa-lib}
BUILDLINK_PACKAGES+=	alsa-lib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}alsa-lib

.if ${ALSA_LIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.alsa-lib+=	alsa-lib>=1.0.18
BUILDLINK_PKGSRCDIR.alsa-lib?=	../../audio/alsa-lib
.endif	# ALSA_LIB_BUILDLINK3_MK

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
