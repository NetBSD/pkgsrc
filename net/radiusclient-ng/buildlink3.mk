# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:27 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	radiusclient-ng

.if !defined(RADIUSCLIENT_NG_BUILDLINK3_MK)
RADIUSCLIENT_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.radiusclient-ng+=	radiusclient-ng>=0.5.5.1
BUILDLINK_PKGSRCDIR.radiusclient-ng?=	../../net/radiusclient-ng
BUILDLINK_DEPMETHOD.radiusclient-ng?=	build

.if ${OPSYS} == "FreeBSD"
BUILDLINK_LDADD.radiusclient-ng+=	-lmd
BUILDLINK_LDFLAGS.radiusclient-ng?=	${BUILDLINK_LDADD.radiusclient-ng}
.endif
.endif # RADIUSCLIENT_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-radiusclient-ng
