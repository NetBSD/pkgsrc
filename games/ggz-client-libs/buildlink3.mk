# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/25 23:24:49 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GGZ_CLIENT_LIBS_BUILDLINK3_MK:=	${GGZ_CLIENT_LIBS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ggz-client-libs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nggz-client-libs}
BUILDLINK_PACKAGES+=	ggz-client-libs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ggz-client-libs

.if ${GGZ_CLIENT_LIBS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ggz-client-libs+=	ggz-client-libs>=0.0.14.1
BUILDLINK_PKGSRCDIR.ggz-client-libs?=	../../games/ggz-client-libs
.endif	# GGZ_CLIENT_LIBS_BUILDLINK3_MK

.include "../../games/libggz/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
