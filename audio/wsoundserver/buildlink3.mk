# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:08 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WSOUNDSERVER_BUILDLINK3_MK:=	${WSOUNDSERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wsoundserver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwsoundserver}
BUILDLINK_PACKAGES+=	wsoundserver

.if !empty(WSOUNDSERVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wsoundserver+=	wsoundserver>=0.4.0nb4
BUILDLINK_PKGSRCDIR.wsoundserver?=	../../audio/wsoundserver
.endif	# WSOUNDSERVER_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
