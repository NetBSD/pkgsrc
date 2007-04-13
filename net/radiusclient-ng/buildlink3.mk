# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/13 19:58:56 bouyer Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RADIUSCLIENT_NG_BUILDLINK3_MK:=	${RADIUSCLIENT_NG_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	radiusclient-ng
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nradiusclient-ng}
BUILDLINK_PACKAGES+=	radiusclient-ng
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}radiusclient-ng

.if !empty(RADIUSCLIENT_NG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.radiusclient-ng+=	radiusclient-ng>=0.5.5.1
BUILDLINK_PKGSRCDIR.radiusclient-ng?=	../../net/radiusclient-ng
BUILDLINK_DEPMETHOD.radiusclient-ng?=	build

.  if ${OPSYS} == "FreeBSD"
BUILDLINK_LDADD.radiusclient-ng+=	-lmd
BUILDLINK_LDFLAGS.radiusclient-ng?=	${BUILDLINK_LDADD.radiusclient-ng}
.  endif
.endif	# RADIUSCLIENT_NG_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
